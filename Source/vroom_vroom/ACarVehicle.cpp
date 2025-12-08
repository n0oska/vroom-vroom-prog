#include "Kismet/GameplayStatics.h"

#include "ACarVehicle.h"

AACarVehicle::AACarVehicle()
{
	PrimaryActorTick.bCanEverTick = true;
	CarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CarMesh"));
	SetRootComponent(CarMesh);
	CarMesh->SetSimulatePhysics(true);

}

void AACarVehicle::BeginPlay()
{
	Super::BeginPlay();

}

void AACarVehicle::MoveForward(float Value)
{
	ThrottleInput = Value;
	
}

void AACarVehicle::MoveRight(float Value)
{
	SteeringInput = Value;
}


void AACarVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector Force = CarMesh->GetForwardVector()*ThrottleInput*70000.0f;
	CarMesh->AddForce(Force);
	
	FVector	Torque = FVector(0, 0, SteeringInput*8000.f);
	CarMesh->AddTorqueInRadians(Torque);

}

void AACarVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AACarVehicle::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AACarVehicle::MoveRight);
}

