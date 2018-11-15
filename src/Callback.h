// Callback.h

#ifndef CALLBACK_H
#define CALLBACK_H

typedef void (*cb_action) (const char* msg, void* user_data);

typedef struct Callback_tag {
	cb_action notifier;
	void* user_data;
} Callback;

#endif // CALLBACK_H
