#include "your_code.h"

/***
 *
 * This file is where you should add you tasks. You already know the structure
 * Required to do so from the work with the simulator.
 *
 * The function yourCodeInit() is set to automatically execute when the
 * quadrotor is started. This is where you need to create your tasks. The
 * scheduler that runs the tasks is already up and running so you should
 * NOT make a call to vTaskStartScheduler();.
 *
 * Below that you can find a few examples of useful function calls and code snippets.
 *
 * For further reference on how this is done: Look into the file stabilizer.c
 * which usually handles the control of the crazyflie.
 *
 ***/

// NO NEED TO CHANGE THIS
static bool emergencyStop = false;
static int emergencyStopTimeout = EMERGENCY_STOP_TIMEOUT_DISABLED;
static StateEstimatorType estimatorType;
// END NO NEED TO CHANGE THIS

void yourCodeInit(void)
{
    estimatorType = getStateEstimator();
	
	/*
   * CREATE AND EXECUTE YOUR TASKS FROM HERE
   */
	
}

/* 
* ADD TASKS HERE
*/


void stabilizerSetEmergencyStop()
{
  emergencyStop = true;
}

void stabilizerResetEmergencyStop()
{
  emergencyStop = false;
}

void stabilizerSetEmergencyStopTimeout(int timeout)
{
  emergencyStop = false;
  emergencyStopTimeout = timeout;
}

/*************************************************
 * CREATE A TASK (Example, a task with priority 5)
 ************************************************/
 //STATIC_MEM_TASK_ALLOC(yourTaskName, configMINIMAL_STACK_SIZE);
 //STATIC_MEM_TASK_CREATE(yourTaskName, yourTaskName,
 //   "TASK_IDENTIFIER_NAME", NULL, 5);

/*************************************************
 * WAIT FOR SENSORS TO BE CALIBRATED
 ************************************************/
// lastWakeTime = xTaskGetTickCount ();
// while(!sensorsAreCalibrated()) {
//     vTaskDelayUntil(&lastWakeTime, F2T(RATE_MAIN_LOOP));
// }



/*************************************************
 * RETRIEVE THE MOST RECENT SENSOR DATA
 *
 * The code creates a variable called sensorData and then calls a function
 * that fills this variable with the latest data from the sensors.
 *
 * sensorData_t sensorData = struct {
 *     Axis3f acc;
 *     Axis3f gyro;
 *     Axis3f mag;
 *     baro_t baro;
 *     zDistance_t zrange;
 *     point_t position;
 * }
 *
 * Before starting the loop, initialize tick:
 * uint32_t tick;
 * tick = 1;
 ************************************************/
// sensorData_t sensorData;
// sensorsAcquire(&sensorData, tick);



/*************************************************
 * RETRIEVE THE SET POINT FROM ANY EXTERNAL COMMAND INTERFACE
 *
 * The code creates a variable called setpoint and then calls a function
 * that fills this variable with the latest command input.
 *
 * setpoint_t setpoint = struct {
 *     uint32_t timestamp;
 *
 *     attitude_t attitude;      // deg
 *     attitude_t attitudeRate;  // deg/s
 *     quaternion_t attitudeQuaternion;
 *     float thrust;
 *     point_t position;         // m
 *     velocity_t velocity;      // m/s
 *     acc_t acceleration;       // m/s^2
 *     bool velocity_body;       // true if velocity is given in body frame; false if velocity is given in world frame
 *
 *     struct {
 *         stab_mode_t x;
 *         stab_mode_t y;
 *         stab_mode_t z;
 *         stab_mode_t roll;
 *         stab_mode_t pitch;
 *         stab_mode_t yaw;
 *         stab_mode_t quat;
 *     } mode;
 * }
 *
 ************************************************/
// state_t state;
// setpoint_t setpoint;
// stateEstimator(&state, tick);
// commanderGetSetpoint(&setpoint, &state);



/*************************************************
 * SENDING OUTPUT TO THE MOTORS
 *
 * The code sends an output to each motor. The output should have the be
 * of the typ unsigned 16-bit integer, i.e. use variables such as:
 * uint16_t value_i
 *
 ************************************************/
// motorsSetRatio(MOTOR_M1, value_1);
// motorsSetRatio(MOTOR_M2, value_2);
// motorsSetRatio(MOTOR_M3, value_3);
// motorsSetRatio(MOTOR_M4, value_4);


/*************************************************
 * LOGGING VALUES THAT CAN BE PLOTTEN IN PYTHON CLIENT
 *
 * We have already set up three log blocks to for the accelerometer data, the
 * gyro data and the setpoints, just uncomment the block to start logging. Use
 * them as reference if you want to add custom blocks.
 *
 ************************************************/

/*
LOG_GROUP_START(acc)
LOG_ADD(LOG_FLOAT, x, &sensorData.acc.x)
LOG_ADD(LOG_FLOAT, y, &sensorData.acc.y)
LOG_ADD(LOG_FLOAT, z, &sensorData.acc.z)
LOG_GROUP_STOP(acc)
*/

/*
LOG_GROUP_START(gyro)
LOG_ADD(LOG_FLOAT, x, &sensorData.gyro.x)
LOG_ADD(LOG_FLOAT, y, &sensorData.gyro.y)
LOG_ADD(LOG_FLOAT, z, &sensorData.gyro.z)
LOG_GROUP_STOP(gyro)
*/

/*
LOG_GROUP_START(ctrltarget)
LOG_ADD(LOG_FLOAT, roll, &setpoint.attitude.roll)
LOG_ADD(LOG_FLOAT, pitch, &setpoint.attitude.pitch)
LOG_ADD(LOG_FLOAT, yaw, &setpoint.attitudeRate.yaw)
LOG_GROUP_STOP(ctrltarget)
*/
