using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor FR;
extern motor FL;
extern motor BR;
extern motor BL;
extern motor Intake;
extern led valve;
extern led EndGame;
extern motor Intake2;
extern motor Shooter;
extern motor Shooter2;
extern pot PC;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );