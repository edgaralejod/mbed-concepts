## Synopsis
This program and document are meant as a learning tool and learning reflections about mbedOS5.
mbedOS is a very powerful SDK to develop C++ firmware for ARM Cortex-M microcontrollers.
I've come to the conclusion that for an end node for IoT applications, Cortex-M processors should be more than enough.
mbedOS is an Open Source Project and the learning curve can be daunting at first.
This document is meant to be a self-learning tool, but it might be useful for others willing to invest the time to learn mbedOS.

I will make this learning development program Open Source in github and some Learning collaboration efforts might arise from it.
I am far from being an expert in mbedOS but my goal is to learn as I write and experiment.

I have 3 mbed ready boards:
    -The Nordic NRF52_DK, which has a M4 processor with Bluetooth support, (Really cool chip!).
    -ST Nucleo-L476RG with a M4 low power core
    -Kinetis/NXP FRDM-K64F with built in Ethernet. 

This hardware should allow to test everything for a connected device.
 
## Motivation

The motivation of this project is to learn more about C++, real-time operating systems, Web-Security and overall "IoT" development practices.
I also want to get more involved with Open Source communities and take advantage of possible massive collaboration.
Between a group of people I know we can build a very cool project, well documented to take an average C or Java programmer and get it up an running with mbed.
I will start with the RTOS concepts, and some C++ things that I still quite don't understand. 

If you are using this code and document, don't hesitate to add comments, and correct me whenever I am not looking at a problem from the right angle.

## Installation

The first steps for me to jump into mbed start with getting the mbed-cli.
Let's assume you can setup python and any required libraries for making it work. I am using an Ubuntu 14 machine.
The easiest way to get mbed-cli is with pip.
````
//I had to install it with sudo, is this a problem? How could I manage using just user space?
sudo pip install mbed-cli
````
*Note
I think I want a way to document the tools I was using at any given time in the development process. 
I am still not quite sure how to do this, I am going to start doing this:(Todo: Review this to make it more efficient)
````
{
    //Unix Timestamp
    date:"1480011701",
    OS:{
        DISTRIB_ID=Ubuntu
        DISTRIB_RELEASE=14.04
        DISTRIB_CODENAME=trusty
        DISTRIB_DESCRIPTION="Ubuntu 14.04.5 LTS"
        NAME="Ubuntu"
        VERSION="14.04.5 LTS, Trusty Tahr"
        ID=ubuntu
        ID_LIKE=debian
        PRETTY_NAME="Ubuntu 14.04.5 LTS"
        VERSION_ID="14.04"
        },
    mbed-cli:"1.0.0",
    python:"2.7.6",
    gcc:"4.8.4",
    GCC_ARM:"gcc-arm-none-eabi-5_4-2016q3"
}
```

#Learning
##RTOS
I think this is the first step in this learning journey. I have some experience in hardware design and small C programs that interact directly with hardware.
RTOS has always been scary for me. But if I'm to learn mbed, this is important.
From the mbedOS blog, I understand that the biggest change for mbedOS 5 is the fact that now the system is based on ARM RTX.
I found this book that will guide me through this reflections. 
"Building Applications with RL-ARM" (RL-ARM: Real-Time Library)

###RTX RTOS Synopsis:
As the book mentions, all my experience so far with developing code for embedded devices is based on interrupt handlers and a background scheduler loop.
The goal of introducing an RTOS is to create code based in Tasks. Every task can be developed and debugged by itself. 
Every RTOS task then should be easier to mantain, document and reuse. 
RTX Kernel
RTX consists of a scheduler that supports: round-robin, pre-emptive and cooperative multitasking of program tasks.
It also supports time and memory management services. Inter-task communication is supported by additional RTOS objects.
These objects include event triggering, semaphores, Mutex and a mailbox system. Interrupt handling also can be accomplished by prioritized tasks.

###Task and Threads
In the documentation for the RTX(which is based in C) the Task is basically an endless loop. 
I think in the mbed OS they use the Thread Class. Concept is the same. I will try to keep it focused in the mbed OS context, but the concepts from RTX are important.
My first test code will be the blinking of LED's using different threads and I will try to do something more interesting later.
I haven't been able to understand completely the Thread class. It might also have to do with my lack of understanding of some C++ concepts.
The documentation is a little inconsistent.

*Note:
mbedOS 5.2 introduced certain changes that are important.
I am sure the haven't had the time to update docs. Threading 

## Tests

I really would like to start doing this in the "Code for Testing" approach.

## Contributors
Edgar Duarte:
www.github.com/edgaralejod

## License

Copyright [2016] [Edgar Duarte]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
