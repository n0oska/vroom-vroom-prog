#include "MyGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "ACarVehicle.h"

void AMyGameMode::StartLocalCoop(int PlayerCount)
{
	for (int i = 0; i < PlayerCount; i++)
	{
		APlayerController* PC = UGameplayStatics::CreatePlayer(GetWorld(), i);
		AACarVehicle* Car = SpawnCarForPlayer(i);
		PC->Possess(Car);
	}
}

AACarVehicle* AMyGameMode::SpawnCarForPlayer(int Index)
{
	FVector SpawnPos = FVector(Index * 300.f, 0.f, 200.f);
	FRotator Rot(0, 0, 0);

	return GetWorld()->SpawnActor<AACarVehicle>(AACarVehicle::StaticClass(), SpawnPos, Rot);
}