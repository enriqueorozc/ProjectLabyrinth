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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* PlayerMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class USpringArmComponent* SpringArm; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UCameraComponent* Camera; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DefaultZoomLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
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
