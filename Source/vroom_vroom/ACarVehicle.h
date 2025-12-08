#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "InputMappingContext.h"

#include "ACarVehicle.generated.h"

UCLASS()
class VROOM_VROOM_API AACarVehicle : public APawn
{
	GENERATED_BODY()

public:
	AACarVehicle();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputMappingContext* IMC_Vroom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* IA_Move;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CarMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AACarVehicle* OtherCar;

	float ThrottleInput;
	float SteeringInput;
	float TargetThrottle;
	float TargetSteering;
	float CurrentSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Car|Physics")
	float MaxAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Car|Physics")
	float AccelerationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Car|Physics")
	float MaxSteeringTorque;

	void Move2D(const FInputActionValue& Value);
};
