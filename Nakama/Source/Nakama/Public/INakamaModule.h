/*
 * Copyright 2019 The Nakama Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Modules/ModuleManager.h"
#include "OnlinePartyInterface.h"
#include "nakama-cpp/Nakama.h"

class INakamaModule : public IModuleInterface
{
public:
    /**
    * Singleton-like access to this module's interface.  This is just for convenience!
    * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
    *
    * @return Returns singleton instance, loading the module on demand if needed
    */
    static inline INakamaModule& Get()
    {
        return FModuleManager::LoadModuleChecked< INakamaModule >("Nakama");
    }

    /**
    * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
    *
    * @return True if the module is loaded and ready to use
    */
    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("Nakama");
    }

    virtual TSharedPtr<IOnlinePartySystem> createOnlinePartySystem(Nakama::NClientPtr client, Nakama::NRtClientPtr rtClient, Nakama::NSessionPtr session) = 0;
    virtual TSharedRef<const FUniqueNetId> getNetId(Nakama::NSessionPtr session) = 0;
};