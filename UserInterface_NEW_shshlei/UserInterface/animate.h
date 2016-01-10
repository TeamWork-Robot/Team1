#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "CaffeDlg.h"

#ifndef _WIN32
#include <unistd.h>
#else
	
void usleep(unsigned int nanosec)
{
    Sleep(nanosec / 1000);
}
#endif

const float PI = 3.1415926;

// --------------- USER INTERFACE VARIABLES -----------------

// Window settings
int windowID;               // Glut window ID (for display)

int windowSize[2];                 // window (x,y) size

float joint_rot = 0;
//More Joint Parameteres

float joint_rightleg = 0.0f;
float joint_neck = 0.0f;
float joint_leftarm =0.0f;
float joint_rightarm = 0.0f;
float joint_leftwrist = 0.0f;
float joint_rightwrist = 0.0f;

//parameters for robot's up down motion
const float MAX_UP = 0.0f;
const float MAX_DOWN = 0.0f;
float UpDown = 0.0f;

//parameters for arm lengthing motion
const float MAX_EXT = 1.25f;
const float MIN_EXT = 0.5f;
float arm_extension = 1.0f;


float temp00=6.6613;
float temp01=280.287;

float temp10=65.8738-6.6613;
float temp11=273.412-280.287;

float temp20=46.4808-65.8738;
float temp21=300.292-273.412;

// Initialization functions
void initGlut(char* winName);
void initGl();


// Callbacks for handling events in glut
void myReshape(int w, int h);
void animate();
void display(void);

// Functions to help draw the object
void drawSquare(float size);
void drawCircle(float radius);

// Initialize glut and create a window with the specified caption 
void initGlut(char* winName)
{
    // Set video mode: double-buffered, color, depth-buffered
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Create window
    glutInitWindowPosition (0, 0);
    glutInitWindowSize(windowSize[0],windowSize[1]);
    windowID = glutCreateWindow(winName);

	
	glutIdleFunc(animate);
	
    // Setup callback functions to handle events
    glutReshapeFunc(myReshape); // Call myReshape whenever window resized
    glutDisplayFunc(display);   // Call display whenever new frame needed 
}

// Performs most of the OpenGL intialization
void initGl(void)
{
    // glClearColor (red, green, blue, alpha)
    // Ignore the meaning of the 'alpha' value for now
    glClearColor(0.7f,0.7f,0.9f,1.0f);
	//glClearColor(0,0,0,0);
}

// Callback idle function for animating the scene
void animate()
{
	static int sig=0;
	switch (sig)
	{
		case 0:
		{
			if(joint_leftarm<=temp00)
			{
				//Rotation angle for left arm
				joint_leftarm+=0.1;
			}
			
			//Rotation angle for right arm
			
			if(joint_leftwrist<=temp01)
			{
				//Rotation angle for left wrist
				joint_leftwrist+=0.1;
			}
			if (joint_leftarm >= temp00&&joint_leftwrist >= temp01)
			{
				Sleep(1000);
				sig = 1;
			}
			break;
		}
			
		case 1:
		{
			if(temp10>=0)
			{
				if(joint_leftarm<=temp00+temp10)
					//Rotation angle for left arm
					joint_leftarm+=0.1;
				
			}
			else 
			{
				if(joint_leftarm>=temp00+temp10)
					//Rotation angle for left arm
					joint_leftarm-=0.1;
			}
			
			if(temp11>=0)
			{
				if(joint_leftwrist<=temp01+temp11)
					//Rotation angle for left arm
					joint_leftwrist+=0.1;
				
			}
			else 
			{
				if(joint_leftwrist>=temp01+temp11)
					//Rotation angle for left arm
					joint_leftwrist-=0.1;
			}
			
			
			//Rotation angle for right arm
			
			if(temp10>=0&&temp11>=0)
			{
				
				if(joint_leftarm>=temp00+temp10&&joint_leftwrist>=temp01+temp11) 
				{
					Sleep(1000);
					sig=2;
				}
			}
			else if(temp10<0&&temp11>=0)
			{
				if(joint_leftarm<temp00+temp10&&joint_leftwrist>=temp01+temp11)
				{
					Sleep(1000);
					sig=2;
				}
			}
			else if(temp10>=0&&temp11<0)
			{
				
				if(joint_leftarm>=temp00+temp10&&joint_leftwrist<temp01+temp11)
				{
					Sleep(1000);
					sig=2;
				}
			}
			else if(temp10<0&&temp11<0)
			{
				
				if(joint_leftarm<temp00+temp10&&joint_leftwrist<temp01+temp11)
				{
					Sleep(1000);
					sig=2;
				}
			}
			break;
		}
		
		case 2:
		{
			if(temp20>=0)
			{
				if(joint_leftarm<=temp00+temp10+temp20)
					//Rotation angle for left arm
					joint_leftarm+=0.1;
				
			}
			else 
			{
				if(joint_leftarm>=temp00+temp10+temp20)
					//Rotation angle for left arm
					joint_leftarm-=0.1;
			}
			
			if(temp21>=0)
			{
				if(joint_leftwrist<=temp01+temp11+temp21)
					//Rotation angle for left arm
					joint_leftwrist+=0.1;
				
			}
			else 
			{
				if(joint_leftwrist>=temp01+temp11+temp21)
					//Rotation angle for left arm
					joint_leftwrist-=0.1;
			}
			
			
			//Rotation angle for right arm
			
			if(temp20>=0&&temp21>=0)
			{
				
				if(joint_leftarm>=temp00+temp10+temp20&&joint_leftwrist>=temp01+temp11+temp21)
				{
					Sleep(1000);
					sig=3;
				}
			}
			else if(temp20<0&&temp11>=0)
			{
				if(joint_leftarm<temp00+temp10+temp20&&joint_leftwrist>=temp01+temp11+temp21)
				{
					Sleep(1000);
					sig=3;
				}
			}
			else if(temp20>=0&&temp11<0)
			{
				
				if(joint_leftarm>=temp00+temp10+temp20&&joint_leftwrist<temp01+temp11+temp21)
				{
					Sleep(1000);
					sig=3;
				}
			}
			else if(temp20<0&&temp11<0)
			{
				
				if(joint_leftarm<temp00+temp10+temp20&&joint_leftwrist<temp01+temp11+temp21)
				{
					Sleep(1000);
					sig=3;
				}
			}
			break;
		}
		
		case 3:
		{
			if(joint_leftarm>=10)
			{
				//Rotation angle for left arm
				joint_leftarm-=0.1;
			}
			
			//Rotation angle for right arm
			
			if(joint_leftwrist<=350)
			{
				//Rotation angle for left wrist
				joint_leftwrist+=0.1;
			}
			if (joint_leftarm <= 10&&joint_leftwrist >= 350)
			{
				Sleep(3000);
				sig = 4;
			}
			break;
		}
		
		case 4:
		{
			if(joint_leftarm>=0)
			{
				//Rotation angle for left arm
				joint_leftarm-=0.1;
			}
			
			//Rotation angle for right arm
			
			if(joint_leftwrist>=0)
			{
				//Rotation angle for left wrist
				joint_leftwrist-=0.1;
			}
			if (joint_leftarm < 0&&joint_leftwrist < 0)
			{
				glutIdleFunc(NULL);
			}
			break;
		}
	}
	
	
	//Rotation angle for right wrist
	
	//joint_rightwrist++;
	
    // Tell glut window to update itself.  This will cause the display()
    // callback to be called, which renders the object (once you've written
    // the callback).
	
    glutSetWindow(windowID);
    glutPostRedisplay();
	
    // Wait 50 us between frames (20 frames per second)
    usleep(50);
}

// Handles the window being resized by updating the viewport
// and projection matrices
void myReshape(int w, int h)
{
    // Setup projection matrix for new window
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w/2, w/2, -h/2, h/2);

    // Update OpenGL viewport and internal variables
    glViewport(0,0, w,h);
    windowSize[0] = w;
    windowSize[1] = h;
}



// display callback
//
// This gets called by the event handler to draw
// the scene, so this is where you need to build
// your scene
void display(void)
{
    // glClearColor (red, green, blue, alpha)
    // Ignore the meaning of the 'alpha' value for now
    glClearColor(0.7f,0.7f,0.9f,1.0f);

    // OK, now clear the screen with the background colour
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

    // Setup the model-view transformation matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw our hinged object
    const float BODY_WIDTH = 60.0f;
    const float BODY_LENGTH = 80.0f;
    const float ARM_LENGTH = 80.0f;
    const float ARM_WIDTH = 20.0f;
	const float TORSO_LENGTH = ARM_LENGTH*1.4;

    // Push the current transformation matrix on the stack
    glPushMatrix();
		// Draw the 'body' //////////////////////////////////////
        glPushMatrix();

			glTranslatef(0.0, UpDown, 0.0);
            // Scale square to size of body
            glScalef(BODY_WIDTH, BODY_LENGTH, 1.0);

            // Set the colour to green
            glColor3f(0.0, 1.0, 0.0);

            // Draw the square for the body
            drawSquare(1.0);
        glPopMatrix();

		
         // Draw the 'torso'//////////////////////////
		glPushMatrix();
		//Translate down to under body
			glTranslatef(0, -BODY_LENGTH/2-ARM_WIDTH/2+UpDown, 0.0);

			glScalef(TORSO_LENGTH , ARM_WIDTH, 1.0);

			//Set the colour of the torso to red
			glColor3f(1.0, 0.0, 0.0);

			//Draw the torso
			drawSquare(1.0);
			
		glPopMatrix();

	
		// Draw the 'left leg'//////////////////////////
		glPushMatrix();
        // Move the arm to the joint hinge
			glTranslatef(-TORSO_LENGTH / 2 + ARM_WIDTH / 2, -BODY_LENGTH/2-ARM_WIDTH*0.4 + UpDown, 0.0);

        // Rotate along the hinge
			 glRotatef(joint_rot, 0.0, 0.0, 1.0);
	
        // Scale the size of the leg
			 glScalef(ARM_WIDTH, ARM_LENGTH, 1.0);

        // Move to center location of leg, under previous rotation
			 glTranslatef(0.0, -0.4, 0.0);

        // Draw the square for the leg
			 glColor3f(0.0, 0.0, 1.0);
			 drawSquare(1.0);

		// Translate to place circle at joint and Descale back to size of 5
			 glTranslatef(0.0, 0.4, 0.0);
			 glScalef(5/ARM_WIDTH, 5/ARM_LENGTH, 1.0);

		//Draw joint circle
			 glColor3f(1.0, 1.0, 1.0);
			 drawCircle(1.0);

		glPopMatrix();

		//Draw the 'right leg'////////////////////////////
		glPushMatrix();
		// Move the leg to the joint hinge
			glTranslatef(TORSO_LENGTH / 2 - ARM_WIDTH / 2, -BODY_LENGTH/2 - ARM_WIDTH*0.4 + UpDown, 0.0);

		// Rotate along the hinge
			glRotatef(joint_rightleg, 0.0, 0.0, 1.0);

		// Scale the size of the leg
			glScalef(ARM_WIDTH, ARM_LENGTH, 1.0);

		// Move to center location of leg, under previous rotation
			glTranslatef(0.0, -0.4, 0.0);

		// Draw the square for the leg
			glColor3f(0.0, 0.0, 1.0);
			drawSquare(1.0);


		// Translate to place circle at joint and Descale back to size of 5
			glTranslatef(0.0, 0.4, 0.0);
			glScalef(5 / ARM_WIDTH, 5 / ARM_LENGTH, 1.0);



		//Draw joint circle
			glColor3f(1.0, 1.0, 1.0);
			drawCircle(1.0);

		glPopMatrix();


		//Draw the 'left arm'/////////////////////////////
		glPushMatrix();

			glTranslatef(-BODY_WIDTH/2+ARM_WIDTH*0.4,2.0+UpDown, 0.0);
			
			glRotatef(joint_leftarm, 0.0, 0.0, 1.0);
			
			
			glScalef(ARM_LENGTH, ARM_WIDTH, 1.0);
			glTranslatef(-0.4, 0.0, 0.0);
			
			glColor3f(0.1, 0.7, 0.7);
			drawSquare(1.0);


			// Translate to place circle at joint and Descale back to size of 5
			glTranslatef(0.4, 0.0, 0.0);
			glScalef(5 / ARM_LENGTH, 5 / ARM_WIDTH, 1.0);

			//Draw joint circle
			glColor3f(1.0, 1.0, 1.0);
			drawCircle(1.0);

			//Translate back to get to the centre of arm
			glScalef(ARM_LENGTH / 5, ARM_WIDTH / 5, 1.0);
			glTranslatef(-0.4, 0.0, 0.0);
			
			//Draw the 'left Hand'///////////////////////

			//Scale back down to 1
			glScalef(1/ARM_LENGTH, 1/ARM_WIDTH, 1.0);
			//Translate to wrist joint
			glTranslatef(-ARM_LENGTH/2+ARM_WIDTH/2, 0, 0);

			//Rotate the wrist joint
			glRotatef(joint_leftwrist, 0.0, 0.0, 1.0);
			
			//hand scaling animation
			glScalef(ARM_LENGTH*arm_extension, ARM_WIDTH, 1.0);
			
			
		
			//Draw the square for the 'hand' add a scaling factor proportional to arm_extension so the wrist stays still
			//and it creates the illusion of elongation.
			
			glTranslatef(-0.4 + (1-arm_extension)*8/(ARM_LENGTH*arm_extension),0 ,0);

			glColor3f(1.0, 0.0, 1.0);
			drawSquare(1.0);

			//Translate to joint location

			glTranslatef(0.4 - (1 - arm_extension) * 8 / (ARM_LENGTH*arm_extension), 0.0, 0.0);
			//Scale back down to 5
			glScalef(5 / (ARM_LENGTH*arm_extension), 5 / ARM_WIDTH, 1.0);

			//Draw joint circle
			glColor3f(1.0, 1.0, 1.0);
			drawCircle(1.0);
			
		

		glPopMatrix();

		//Draw the 'right arm'//////////////////////////
		glPushMatrix();

			glTranslatef(BODY_WIDTH/2-ARM_WIDTH*0.4, 2.0+UpDown, 0.0);

			glRotatef(joint_rightarm, 0.0, 0.0, 1.0);

			glScalef(ARM_LENGTH, ARM_WIDTH, 1.0);

			glTranslatef(0.4, 0, 0);

			//draw square for 'arm'
			glColor3f(0.1, 0.7, 0.7);

			drawSquare(1.0);


			// Translate to place circle at joint and Descale back to size of 5
			glTranslatef(-0.4, 0.0, 0.0);
			glScalef(5 / ARM_LENGTH, 5 / ARM_WIDTH, 1.0);



			//Draw joint circle
			glColor3f(1.0, 1.0, 1.0);
			drawCircle(1.0);


			//Draw the 'right Hand'//////////////////////
			glScalef( ARM_LENGTH/5,  ARM_WIDTH/5, 1.0);
			glTranslatef(0.4, 0.0, 0.0);
			
			//scale back down to 1
			glScalef(1 / ARM_LENGTH, 1 / ARM_WIDTH, 1.0);

			//Translate to wrist joint
			glTranslatef(ARM_LENGTH/2 - ARM_WIDTH/2, 0, 0);

			//Rotate the wrist joint
			glRotatef(joint_rightwrist, 0.0, 0.0, 1.0);

			//hand scaling animation
			glScalef(ARM_LENGTH*arm_extension, ARM_WIDTH, 1.0);

			//Draw the square for the 'hand' add a scaling factor proportional to arm_extension so the wrist stays still
			//and it creates the illusion of elongation.

			glTranslatef(0.4 - (1 - arm_extension) * 8 / (ARM_LENGTH*arm_extension), 0, 0);

			glColor3f(1.0, 0.0, 1.0);
			drawSquare(1.0);

			//Translate to joint location

			glTranslatef(-0.4 + (1 - arm_extension) * 8 / (ARM_LENGTH*arm_extension), 0, 0);
			//Scale back down to 5
			glScalef(5 / (ARM_LENGTH*arm_extension), 5 / ARM_WIDTH, 1.0);

			//Draw joint circle
			glColor3f(1.0, 1.0, 1.0);
			drawCircle(1.0);



		glPopMatrix();

		//Draw the Neck and Head//////////////////////////////////
		glPushMatrix();
			
			glTranslatef(0.0, BODY_LENGTH/2-ARM_WIDTH/2+UpDown, 0.0);
			glRotatef(joint_neck, 0.0, 0.0, 1.0);
			glScalef(ARM_WIDTH, ARM_LENGTH/1.25, 1.0);
			glTranslatef(0.0, 0.4, 0);
			glColor3f(0.1, 0.7, 0.7);
			drawSquare(1.0);


			// Translate to place circle at joint and Descale back to size of 5
			glTranslatef(0.0, -0.4, 0.0);
			glScalef(5 / ARM_WIDTH, 5 / (ARM_LENGTH/1.25), 1.0);

			//Draw joint circle
			glColor3f(1.0, 1.0, 1.0);
			drawCircle(1.0);

			//Translate back to get to the centre of neck
			glScalef( ARM_WIDTH/5,  (ARM_LENGTH/1.25)/5, 1.0);
			glTranslatef(0.0, 0.4, 0.0);


			//Draw Head
			//Scale back down to 1
			
			glScalef(1 / ARM_WIDTH, 1 / (ARM_LENGTH/1.25), 1.0);
			glTranslatef(0.0, BODY_WIDTH-ARM_WIDTH/2, 0.0);
			glScalef(ARM_LENGTH, ARM_WIDTH*2.5, 1.0);

			glColor3f(1.0, 0.0, 1.0);
			drawSquare(1.0);
			//Draw the eyes
			//Scale down to 1
			glScalef(1/ARM_LENGTH,1/ (ARM_WIDTH*2.5), 1.0);
			
			//Draw the left eye
			glTranslatef(-ARM_WIDTH, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			drawCircle(10.0);
			drawCircle(6.0);
			//Draw the right eye
			glTranslatef(ARM_WIDTH * 2, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			drawCircle(10.0);
			drawCircle(6.0);
			
		glPopMatrix();

		//Big Cup
		glPushMatrix();
			glTranslatef(-100, 60, 0);
			glScalef(25, 45, 1);
			glColor3f(0.5, 0.4, 0.6);
			drawSquare(1);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(100, 60, 0);
			glScalef(25, 45, 1);
			glColor3f(0.5, 0.4, 0.6);
			drawSquare(1);
		glPopMatrix();
		//Small Cup
		glPushMatrix();
			glTranslatef(-140, 60, 0);
			glScalef(20, 40, 1);
			glColor3f(0.5, 0.4, 0.6);
			drawSquare(1);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(140, 60, 0);
			glScalef(20, 40, 1);
			glColor3f(0.5, 0.4, 0.6);
			drawSquare(1);
		glPopMatrix();
		//Kabu Caffe
		glPushMatrix();
			glTranslatef(-110, -30, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();
			glPushMatrix();
			glTranslatef(110, -30, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();
		//Natie Caffe
		glPushMatrix();
			glTranslatef(-110, -40, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();
			glPushMatrix();
			glTranslatef(110, -40, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();
		//Moka Caffe
		glPushMatrix();
			glTranslatef(-110, -50, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();
			glPushMatrix();
			glTranslatef(110, -50, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();
		//LanShan Caffe
		glPushMatrix();
			glTranslatef(-110, -60, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(110, -60, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();

		//ShaTang
		glPushMatrix();
			glTranslatef(-130, -30, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(130, -30, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();
		//FangTang
		glPushMatrix();
			glTranslatef(-130, -40, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(130, -40, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();
		//XianNai
		glPushMatrix();
			glTranslatef(-130, -50, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(130, -50, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();
		//NaiYou
		glPushMatrix();
			glTranslatef(-130, -60, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(130, -60, 0);
			glScalef(5, 5, 1);
			glColor3f(0.5, 0.4, 1);
			drawSquare(1);
		glPopMatrix();
		/*glPushMatrix();
		glTranslatef(80, 80, 0);
		glRotatef(joint_leftarm, 0, 0, 1.0);
		glScalef(5, 4, 1);
		glColor3f(1.0, 1.0, 1.0);
		drawCircle(10.0);
		glPopMatrix();
		

		glPushMatrix();
		
		glRotatef(joint_leftarm, 0, 0, 1.0);
		glTranslatef(80, 80, 0);
		glScalef(5, 5, 1);
		glColor3f(1.0, 1.0, 1.0);
		drawCircle(10.0);
		glPopMatrix();*/


    // Retrieve the previous state of the transformation stack
    glPopMatrix();


    // Execute any GL functions that are in the queue just to be safe
    glFlush();

    // Now, show the frame buffer that we just drew into.
    // (this prevents flickering).
    glutSwapBuffers();
}


// Draw a square of the specified size, centered at the current location
void drawSquare(float width)
{
    // Draw the square
    glBegin(GL_POLYGON);
    glVertex2d(-width/2, -width/2);
    glVertex2d(width/2, -width/2);
    glVertex2d(width/2, width/2);
    glVertex2d(-width/2, width/2);
    glEnd();
}


void drawCircle(float radius){
	glBegin(GL_LINES);
	for (float i = 0; i < 360; i++){
		glVertex2d(radius*sin(i), radius*cos(i));
		
	}
	glEnd();
}