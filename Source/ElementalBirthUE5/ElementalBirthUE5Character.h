// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ElementalBirthUE5Character.generated.h"

class UNiagaraSystem;
class UTimerHandler;

UCLASS(config=Game)
class AElementalBirthUE5Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AElementalBirthUE5Character();

	
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FX", meta = (AllowPrivateAccess = "true"))
	//class UNiagaraSystem* FXTargetRock;


	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

	

	//Density Management
	UPROPERTY(EditAnywhere,  Category = DensityElem)
	float DensityElem = 0.5f;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

#pragma region MyRegion

	//Make the Player dash 
	void Dash();

	UPROPERTY(EditAnywhere, Category = Dash)
	float DashSpeed = 1500.f;

	UPROPERTY(EditAnywhere, Category = Dash)
	float DashDuration = 1.f;
	UPROPERTY(EditAnywhere, Category = Dash)
	class UTimerHandler* TimerHandlerDashDuration = NULL;

	void LaunchDashDurationTimer();

	UPROPERTY(EditAnywhere, Category = Dash)
	float DashSlowDown = 1.f;
	UPROPERTY(EditAnywhere, Category = Dash)
	class UTimerHandler* TimerHandlerDashSlowDown = NULL;

	void LaunchDashSlowDownTimer();
	


#pragma endregion

	void CalculateTimers(float _DeltaTime);

	virtual void Tick(float DeltaSeconds) override;

	

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

