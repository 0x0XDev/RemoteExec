## RemoteExec
C/C++ Library for Executing Code in another Process 




#### Methods
`RemoteExecSystem()`: Executes the give command via system() func.

`RemoteExecDlopen()`: Loads a dynamic library from the give path via dlopen() func.


```
|v1|
  Initial Commit

|v2|
  Code better organized, future proof for easy creation of new code modules
  Cons:
  - Size increased from 14kb to 21kb
  - Since functions from c++ standard library is used, ever project that uses this library has to link them either by adding `-lstdc++` to `OTHER_LINKER_FLAGS` or adding a `.cpp` file to their project (can be an empty one)
```


### Usage Example (Swift):
```Swift
import Foundation

let pid = find_pid_by_name("Finder");
assert(pid != 0);

var port: task_t = task_t(MACH_PORT_NULL)
let kr = task_for_pid(mach_task_self_, pid, &port)
assert(kr == KERN_SUCCESS);

let command = "/System/Applications/Utilities/Terminal.app/Contents/MacOS/Terminal &";
RemoteExecSystem(port, command)

let dlpath = "/path/to/any.dylib"
RemoteExecDlopen(port, dlpath)

```

> Note:
Getting the Task Port may require partly disabling SIP and running as root, depending on the OSX-Version
