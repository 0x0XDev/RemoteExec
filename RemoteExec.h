//
//  RemoteExec.hpp
//  RemoteExec
//
//  Copyright © 2020 Anonymouz. All rights reserved.
//

#ifndef RemoteExec_hpp
#define RemoteExec_hpp

#include <stdio.h>
#include <mach/mach.h>
#include <libproc.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Main */
	mach_error_t RemoteExecSystem(task_t remoteTask, const char* command);
	mach_error_t RemoteExecDlopen(task_t remoteTask, const char* path);

/* Tools */
	pid_t find_pid_by_name(const char *name);


#ifdef __cplusplus
}
#endif

#endif /* RemoteExec_hpp */
