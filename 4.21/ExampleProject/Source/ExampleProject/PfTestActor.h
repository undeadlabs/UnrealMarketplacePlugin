//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "GameFramework/Actor.h"
#include "TestFramework/PlayFabTestRunner.h"

#include "ACloudScriptTestResultUploader.h"

#include "PfTestActor.generated.h"

UCLASS()
class APfTestActor : public AActor, public IPlayFabTestRunner
{
    GENERATED_BODY()

public:
    ///////////////////// Actor stuff /////////////////////
    APfTestActor(); // Sets default values for this actor's properties
    virtual void BeginPlay() override; // Called when the game starts or when spawned
    virtual void Tick(float DeltaTime) override; // Called every frame
    virtual void EndPlay(const EEndPlayReason::Type reason) override;

private:
    UPROPERTY()
    bool _submitCloudScript;

    UFUNCTION()
    bool TestsAreComplete() const;
};
