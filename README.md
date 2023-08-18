# computer-graphics-project


## Introduction
This project demonstrates the natural environment of Baitul Mukarram, the National Mosque of Bangladesh, which is located in Dhaka. This project uses 2D animation created with OpenGL. The identical sight is displayed in three distinct modes in this particular scenario. A keyboard is used to manually controls these three modes. The azan plays in the background.
## Elements of the view

`Baitul Mukarram Mosjid Complex` , `Aeroplanes` , `Sun` , `Clouds` , `The Sky` , `Water Pool` , `Garden` , `Trees` , `Lights` , `People`

## Views of the Project
In a static context, three separate views are displayed. These are 
**Day Views**

![BM_Day](https://github.com/NurulAfsar96/computer-graphics-baitul-mukarram-view/assets/90999889/f34caa1c-a909-4bcb-aa00-cbc8f98f7257)

**Night Views**

![BM_Night](https://github.com/NurulAfsar96/computer-graphics-baitul-mukarram-view/assets/90999889/5693bac6-ce5c-43ec-80c6-716e2511ed1b)

**Rain Views**

![BM_Rain](https://github.com/NurulAfsar96/computer-graphics-baitul-mukarram-view/assets/90999889/7af4c064-2fa9-4c34-9bc6-b802aa37c59b)

## Tools Used

- **IDE :** CodeBlocks
- **Language :** C++
- **Library :** OpenGL

## Interaction with Program
We can have an interaction with this project using popular input device like mouse and key board are used to interact with this program.

- **For Azan-**
     "Key A" :- start Azan, "Key S" :- stop Azan
- **For Day View-**
     "Key D" :- To view the day scenario
- **For Night View-**
     "Key N" :- To view the night scenario
- **For Rain View-**
     "Key R" :- To view the rain scenario

## Functions used in this program
- **glutInit( )** : interaction between the windowing system and OPENGL is initiated.
- **glutInitDisplayMode( )** : used when double buffering is required and depth information is required.
- **glutCreateWindow( )** : this opens the OPENGL window and displays the title at top of the window.
- **glutInitWindowSize( )** : specifies the size of the window.
- **glutInitWindowPosition( )** : specifies the position of the window in screen co-ordinates. 
- **glutKeyboardFunc( )** : handles normal ASCII symbols.
- **glutSpecialFunc( )** : handles special keyboard keys. 
- **glutReshapeFunc( )** : sets up the callback function for reshaping the window.  
- **glutIdleFunc( )** : this handles the processing of the background.  
- **glutDisplayFunc( )** : this handles redrawing of the window  
- **glutMainLoop ( )** : this starts the main loop, it never returns.
- **glViewport ( )** : used to set up the viewport.  
- **glVertex3fv ( )** : used to set up the points or vertices in three dimensions.  
- **glColor3ub ( )** : used to render color to faces.
- **glutPostRedisplay()** : used to trigger an automatic redrawal of the object.
-  **glMatrixMode()** : used to set up the required mode of the matrix.
- **glLoadIdentity ()** : used to load or initialize to the identity matrix.
- **glTranslatef ()** : used to translate or move the rotation centre from one point to another in three dimensions.
- **glRotatef()** : used to rotate an object through a specified rotation angle.
- **glFlush( )** : used to flush the pipeline

## Authors
[`Nurul Afsar`](https://github.com/NurulAfsar96/)

