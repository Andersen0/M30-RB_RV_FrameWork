# OGMA

The purpose of this directory is to teach you how to use OGMA correctly and therefore become a better person.
This directory will contain all files and their accompanying instructions in relation to OGMA.

[OGMA github](https://github.com/nasa/ogma)

## Demonstrative files

The OgmaDemoFiles directory contains all the files that are being used for testing in the work-in-progress project.

Of these files there are files that work as intended and are operational (_OP).
Files that are not operational (_XOP) or have an error message to their name (_ERR) will be documented here:

| File | Error Message |
| ----------- | ----------- |
| test_OP.hs  | Operational |


How the db file should look like for ogma ros implementation:
```haskell
("distance_to_target","int","/scan","float32")
("classifier","int","/sRobotClassifier","int")
("alert","bool","/sRobotAlert","bool")
("pause","bool","/sRobotPause","bool")
("slowdown","bool","/sRobotSlowdown","bool")
("state","int","/sRobotState","int")
("turnoffUVC","bool","/sRobotTurnoffUVC","bool")
```
