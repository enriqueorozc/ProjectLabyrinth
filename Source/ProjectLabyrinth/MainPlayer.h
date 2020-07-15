// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MainPlayer.generated.h"

UCLASS()
class PROJECTLABYRINTH_API AMainPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainPlayer();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PlayerMesh;

	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm; 

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera; 

	UPROPERTY(EditAnywhere)
	float DefaultZoomLength;

	UPROPERTY(EditAnywhere)
	FRotator DefaultCameraRotation; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void HorizontalMovement(float Value);
	void VerticalMovement(float Value);

};
