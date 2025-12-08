#include "ACarVehicle.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"

AACarVehicle::AACarVehicle()
{
	PrimaryActorTick.bCanEverTick = true;

	CarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CarMesh"));
	SetRootComponent(CarMesh);
	CarMesh->SetSimulatePhysics(true);

	MaxAcceleration = 70000.f;
	AccelerationSpeed = 200000.f;
	MaxSteeringTorque = 800000.f;
	ThrottleInput = 0.f;
	SteeringInput = 0.f;
	CurrentSpeed = 0.f;
}

void AACarVehicle::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(IMC_Vroom, 0);
		}
	}
}

void AACarVehicle::Move2D(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();

	TargetThrottle = Input.Y;
	TargetSteering = Input.X;
}

void AACarVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentSpeed = FMath::FInterpTo(CurrentSpeed, TargetThrottle, DeltaTime, AccelerationSpeed);

	FVector Force = CarMesh->GetForwardVector() * CurrentSpeed * MaxAcceleration;
	CarMesh->AddForce(Force);

	if (FMath::Abs(CurrentSpeed) < 0.05f)
	{
		SteeringInput = TargetSteering;
	}
	else
	{
		SteeringInput = 0.f;
	}

	FVector Torque(0, 0, SteeringInput * MaxSteeringTorque);
	CarMesh->AddTorqueInRadians(Torque);
}

void AACarVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AACarVehicle::Move2D);
	}
}
