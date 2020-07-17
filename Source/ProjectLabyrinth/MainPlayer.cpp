// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayer.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values
AMainPlayer::AMainPlayer()
{

	// Spring Arm Defaults
	DefaultCameraRotation = FRotator(-30.0, 0.0, 0.0); // Pitch (Y), Yaw (Z), Roll (X)
	DefaultZoomLength = 400.0f;


 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");



	// Create root component for PlayerMesh
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>("Player Mesh");
	RootComponent = PlayerMesh; 

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));

	if (SphereAsset.Succeeded())
	{
		PlayerMesh->SetStaticMesh(SphereAsset.Object);
	}


	// Create a CameraBoom
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = DefaultZoomLength;
	SpringArm->SetRelativeRotation(DefaultCameraRotation);
	SpringArm->bDoCollisionTest = false; 
	SpringArm->bInheritPitch = false;
	SpringArm->bEnableCameraLag = true; 

	// Create a Camera
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("HorizontalMovement", this, &AMainPlayer::HorizontalMovement);
	PlayerInputComponent->BindAxis("VerticalMovement", this, &AMainPlayer::VerticalMovement);
}

void AMainPlayer::HorizontalMovement(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void AMainPlayer::VerticalMovement(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}
