
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode.generated.h"

class AACarVehicle;
UCLASS()
class VROOM_VROOM_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void StartLocalCoop(int PlayerCount);

	AACarVehicle* SpawnCarForPlayer(int Index);
};
