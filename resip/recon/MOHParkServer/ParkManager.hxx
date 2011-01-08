#if !defined(ParkManager_hxx)
#define ParkManager_hxx

#include <map>
#include <deque>
#include "../UserAgent.hxx"
#include "../HandleTypes.hxx"

namespace resip
{
class SipMessage;
}

namespace mohparkserver
{
class Server;
class ParkOrbit;

class ParkManager
{
public:
   ParkManager(Server& server);
   virtual ~ParkManager(); 

   void startup();
   void shutdown();

   bool isMyProfile(recon::ConversationProfile& profile);
   void parkParticipant(recon::ParticipantHandle participantHandle, const resip::SipMessage& msg);
   void incomingParticipant(recon::ParticipantHandle participantHandle, const resip::SipMessage& msg);
   bool removeParticipant(recon::ParticipantHandle participantHandle);

private:
   Server& mServer;
   resip::SharedPtr<recon::ConversationProfile> mConversationProfile;
   std::deque<unsigned long> mFreeOrbitList;

   ParkOrbit* getOrbit(unsigned long orbit);
   typedef std::map<unsigned long, ParkOrbit*> OrbitMap;
   OrbitMap mOrbits;

   typedef std::map<unsigned long, resip::SharedPtr<recon::ConversationProfile> > OrbitProfileMap;
   OrbitProfileMap mOrbitProfiles;
};
 
}

#endif

/* ====================================================================

 Copyright (c) 2011, SIP Spectrum, Inc.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are 
 met:

 1. Redistributions of source code must retain the above copyright 
    notice, this list of conditions and the following disclaimer. 

 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution. 

 3. Neither the name of SIP Spectrum nor the names of its contributors 
    may be used to endorse or promote products derived from this 
    software without specific prior written permission. 

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
 A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 ==================================================================== */
