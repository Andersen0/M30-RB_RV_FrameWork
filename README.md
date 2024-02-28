# M30-RB Runtime Verification Framework

This is the collected repository consisting of all parts of a framework for runtime verification of ROS2 systems,
including instructions as well as personal findings and goals.

## The task:

Put together a framework for autonomous generation of monitors from natural language with an end-goal of easy runtime verification of ROS2 systems.
The task builds upon previous work done by PhD candidate Mustafa Adam and the developers at NASA behind FRET and OGMA.

### Software developed by NASA, utilized in the framework:
[FRET github](https://github.com/NASA-SW-VnV/fret/tree/master)

[OGMA github](https://github.com/nasa/ogma)

## Workflow

### ROBOTOOL (optional)

### FRET
1. (optional) import requirements from ROBOTOOL
1. Create requirements in FRET, either following the templates or by using the fields system. Pay attention to what should be assumptions (done by adding "assumption" to requirements name). 
2. Apply variable mapping. Check chart for information regarding the difference between the classes and how to do this correctly.
3. Check realizability. If unrealizable go back to step 1.
4. If realizable export json of project with requirements and variables.
   
### OGMA

1. Create copilot monitors
2. create ROS2 structure
3. Compile the copilot code and move the .h and .c files to the ROS2 directory


### ROS2

### Testing



<img src="workflow.jpg" style="transform: rotate(90deg);" />
