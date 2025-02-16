// Please don't steal

#pragma once

#include "CoreMinimal.h"
#include "DoubleAgent/InteractInterface.h"
#include "../Security/RadioHub.h"
#include "DoubleAgent/Security/CameraHub.h"
#include "GameFramework/Actor.h"
#include "PowerBox.generated.h"

UCLASS()
class DOUBLEAGENT_API APowerBox : public AActor, public IInteractInterface{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerBox();

	UPROPERTY(Category="Power States", BlueprintReadWrite, Replicated, EditAnywhere)
	bool bLightsOn = true;
	UPROPERTY(Category="Power States", BlueprintReadWrite, Replicated, EditAnywhere)
	bool bLandlinesOn = true;
	UPROPERTY(Category="Power States", BlueprintReadWrite, Replicated, EditAnywhere)
	bool bRadiosOn = true;
	UPROPERTY(Category="Power States", BlueprintReadWrite, Replicated, EditAnywhere)
	bool bCamerasOn = true;
	UPROPERTY(Category="Power States", BlueprintReadWrite, Replicated, EditAnywhere)
    bool bPowerCut = false;
	
	UPROPERTY(Category="Hub References", BlueprintReadWrite)
	ARadioHub* RadioHub;
	UPROPERTY(Category="Hub References", BlueprintReadWrite)
	ACameraHub* CameraHub;

	UPROPERTY()
	TArray<AActor*> tempArray;
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void TurnLightsOn();
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void TurnLightsOff();
	UFUNCTION(BlueprintCallable)
	void TurnCamerasOff();
	UFUNCTION(BlueprintCallable)
	void TurnCamerasOn();
	UFUNCTION(BlueprintCallable)
	void TurnLandlinesOn();
	UFUNCTION(BlueprintCallable)
	void TurnLandlinesOff();
	UFUNCTION(BlueprintCallable)
	void TurnRadiosOn();
	UFUNCTION(BlueprintCallable)
	void TurnRadiosOff();
	
	UFUNCTION(BlueprintCallable)
	void CutPower();
	UFUNCTION(BlueprintCallable)
	bool TurnAllPowerOn();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interaction") //Setting up the Interact interface to use it's functionality in C++
    void Interact(AActor* Interactor);
	virtual void Interact_Implementation(AActor* Interactor) override;
	
	//Base overrides
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(::TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
