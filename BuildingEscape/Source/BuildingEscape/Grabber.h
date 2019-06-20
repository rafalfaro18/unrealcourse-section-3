// Copyright (c) 2019 Rafael Alfaro

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Classes/Components/InputComponent.h"
#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	// Ray-cast and grab what's in reach.
	void Grab();

	// Called when grab is released.
	void Release();

	// Find (asumed) attached physics handle
	void FindPhysicsHandleComponent();

	//Setup (asumed) attached input component
	void SetupInputComponent();

	// Returns current end of reach line
	FVector GetReachLineEnd();

	// Returns current start of reach line
	FVector GetReachLineStart();

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
};
