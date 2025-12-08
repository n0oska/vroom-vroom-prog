
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyGameMode.h"

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
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CarMesh;
	

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AACarVehicle* OtherCar;
	
	float ThrottleInput;
	float SteeringInput;
	
	void MoveForward(float Value);
	void MoveRight(float Value);
public:	

};
