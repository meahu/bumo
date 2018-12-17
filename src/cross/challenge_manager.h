#ifndef CHALLENGE_MANAGER_H_
#define CHALLENGE_MANAGER_H_

#include <utils/singleton.h>
#include <utils/thread.h>
#include "ledger/ledger_frm.h"
#include <cross/cross_utils.h>
namespace bumo {
	class ChallengeManager :public utils::Runnable{
	public:
		ChallengeManager();
		virtual ~ChallengeManager();
		bool Initialize();
		bool Exit();
		void ChallengeNotify(const protocol::MessageChannel &message_channel);
	private:
		void HandleChallengeSubmitHead(const protocol::MessageChannel &message_channel);
		void Run(utils::Thread *thread);
	private:
		bool enabled_;
		utils::Thread *thread_ptr_;
		int64_t chain_seq_;
	};
}

#endif