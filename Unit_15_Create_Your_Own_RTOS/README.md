# IbrahimOS

#### ```⚠️ This project is made for educational and learning purposes and it may contain faults that I didn't  discover yet. If you find any, please do a pull request or fork the project to add the modifications.```

Ibrahim OS is a Real-Time Operating System written from scratch, targeting embedded devices, and is built on the ARM CMSIS V5 Library for easy porting  

### Features:  
1- Fair scheduling policy: featuring a full-preemptive priority-based scheduler, IbrahimOS supports a round-robin policy for same-priority tasks.  
  
2- Low resource consumption: IbrahimOS only consumes 7% of the Cortex-M3 CPU usage in the idle state (no tasks are running), thanks to the "WFE" instruction which allows the CPU to enter sleep mode while not running any tasks  
  
3- Event and Time triggered scheduler: IbrahimOS allows the user to choose between letting the tasks activate/terminate either by themselves or by an event, or by using delays to run the tasks periodically! 
  
4- Easy task synchronization: IbrahimOS supports Mutexs, which allows one task to wait for an acquired mutex and to be activated once the mutex is released!  
  
5- No mutex releases by mistake: IbrahimOS respects the Mutex ownership concept and allows only the task that is holding the mutex to release it.   
  
6- Priority Inversion is no more: IbrahimOS features the priority ceiling technique which helps in avoiding the priority inversion problem!  

### Supported APIs:  

- **IbrahimOS_Init:** Initializes the OS control and buffers
- **IbrahimOS_CreateTask:** Creates the task object in the OS and initializes the task's stack area
- **IbrahimOS_ActivateTask:** Sends a task to the ready queue to be scheduled
- **IbrahimOS_TerminateTask:** Sends a task to the suspended state
- **IbrahimOS_StartOS:** Starts the OS scheduler to begin running tasks
- **IbrahimOS_TaskWait:** Sends a task to the waiting state for a specific amount of Ticks
- **IbrahimOS_AcquireMutex:** Tries to acquire a mutex if available
- **IbrahimOS_ReleaseMutex:** Releases a mutex and starts the next task that is in the queue (if found)

### Examples:  
In this example there are 3 tasks with the same priority, running sequentially with the round-robin scheduling policy   
![enter image description here](https://github.com/Piistachyoo/IbrahimOS/blob/main/RoundRobinExample.gif?raw=true)

This example shows 3 tasks, each running with a specific delay, task 1 runs every 100ms, task 2 runs every 300ms, and task 3 runs every 500 ms
![enter image description here](https://github.com/Piistachyoo/IbrahimOS/blob/main/Time_Delay_Example.gif?raw=true)

This example shows the CPU utilization when the OS is not running any tasks, the CPU load is at 7% so it is not consuming excessive energy or resources
![enter image description here](https://github.com/Piistachyoo/IbrahimOS/blob/main/CPU_Utilization_Example.gif?raw=true)

