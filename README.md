# Computer-Graphics-Project

## Introduction
This project demonstrates the natural environment of Baitul Mukarram, the National Mosque of Bangladesh, which is located in Dhaka. This project uses 2D animation created with OpenGL. The identical sight is displayed in three distinct modes in this particular scenario. A keyboard is used to manually controls these three modes. The azan plays in the background.
## Elements of the view

- The main Element is the Baitul Mukarram Mosjid
- Aeroplanes: The Aeroplanes are flying above the mosque
- Sun
- Clouds
- The Sky
- Water Pool
- Garden
- Trees
- Lights
- People
## Views of the Project
In a static context, three separate views are displayed. These are 
1. **Day Views**

   ![BM_Day](https://github.com/NurulAfsar96/computer-graphics-baitul-mukarram-view/assets/90999889/ffafc453-b22f-4d31-ad58-5011b338ab1a)

2. **Night Views**
   
   ![BM_Night](https://github.com/NurulAfsar96/computer-graphics-baitul-mukarram-view/assets/90999889/a94daf0b-36a9-4552-afb7-de5e098e1edd)

3. **Rain Views**
   
![BM_Rain](https://github.com/NurulAfsar96/computer-graphics-baitul-mukarram-view/assets/90999889/6ec3f00a-aa75-4938-89b7-d2ff9632ac31)


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

