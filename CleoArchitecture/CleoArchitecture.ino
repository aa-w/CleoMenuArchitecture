/**
    CleOProgram Architecture ----------------
    Alex.W - November - 2019

    This is a super basic architecture for CleO Programs with multiple tab toggleability
    ------------------------

    The program is designed so that you have a UI and Backend handler for each of the tabs, the backend will only run when the front end is selected
    There is also a toggle button for settings in each tab
*/

#include <CleO.h>

//Define Constants used for tag declaration
//All defines are in CAPS to avoid replace conflicts

//CleO Screen Setup
#define SCREENWIDTH  480
#define SCREENHEIGHT 320

//Buffer Define values
#define ARRAYSIZE 8
#define BUFFERSIZE 10

//CleO Button Tag Values - Replace these with your functions
#define TAB1 1 //TAB1
#define TAB2 2 //TAB2
#define TAB3 3 //TAB2
#define TAB4 4 //TAB3

#define SETTINGS 5 //Settings

//Settings buttons
#define INCREMENTBUTTON 6
#define DECREMENTBUTTON 7
#define DONEBUTTON 8

byte MenuMode = 1; //Top level menu mode - starts on 1 for simplicity
byte tag; //Defines UI Events based on touches

////////////// SETTINGS VAIRABLES //////////////

bool ShowSettings = false;
long SettingsDebounceTimer;

////////////// TAB1 GLOBALS //////////////

////////////// TAB2 GLOBALS //////////////

////////////// TAB3 GLOBALS //////////////

////////////// TAB4 GLOBALS //////////////


void setup()
{
  ////////////// CLEO ANIMATION SETUP //////////////
  CleO.begin();
  CleO.DisplayRotate(2, 0);
  CleO.SetBackgroundcolor(WHITE);

  // IDLE ANIMATION //
  CleO.LineWidth(5);

///////////// INTRO ANIMATION //////////////
  Intro();

}

void loop()
{

  //BACKEND
  BackendHandler();

  //UI LOOP
  UIHandler();

  //Touch Handling
  TouchHandler();

}

void UIHandler() //Handles User Interfaces
{
  //Draw Stage
  CleO.Start();

  //Displays the Main Menu to the User (Top Bar)
  MainMenu();

  //Page Switch Case
  switch (MenuMode)
  {
    case 1:
      CleO.StringExt(FONT_SANS_7, (0.50 * SCREENWIDTH), (0.55 * SCREENHEIGHT), GREY85, MM, 0, 0, "1");

      if (ShowSettings == true)
      {
        Tab1Settings();
      }
      else
      {
        Tab1Page();
      }
      break;
    case 2:
      CleO.StringExt(FONT_SANS_7, (0.50 * SCREENWIDTH), (0.55 * SCREENHEIGHT), GREY85, MM, 0, 0, "2");
      if (ShowSettings == true)
      {
        Tab2Settings();
      }
      else
      {
        Tab2Page();
      }
      break;
    case 3:
      CleO.StringExt(FONT_SANS_7, (0.50 * SCREENWIDTH), (0.55 * SCREENHEIGHT), GREY85, MM, 0, 0, "3");
      if (ShowSettings == true)
      {
        Tab3Settings();
      }
      else
      {
        Tab3Page();
      }
      break;
    case 4:
      CleO.StringExt(FONT_SANS_7, (0.50 * SCREENWIDTH), (0.55 * SCREENHEIGHT), GREY85, MM, 0, 0, "4");
      if (ShowSettings == true)
      {
        Tab4Settings();
      }
      else
      {
        Tab4Page();
      }
      break;
    default:
      break;
  }

  AnimationLoop();

  CleO.Show();
}

void BackendHandler() //Handlers the Communication and operation
{
  switch (MenuMode)
  {
    case 1:
      Tab1Handler();
      break;
    case 2:
      Tab2Handler();
      break;
    case 3:
      Tab3Handler();
      break;
    case 4:
      Tab4Handler();
      break;
    default:
      break;
  }

}

// ------------------------ BACKEND ----------------------------------------

void Tab1Handler() //Serial Backend
{
  //ADD CODE TO RUN WHILE THIS TAB IS ACTIVE
}

void Tab2Handler()
{
  //ADD CODE TO RUN WHILE THIS TAB IS ACTIVE
}

void Tab3Handler()
{
  //ADD CODE TO RUN WHILE THIS TAB IS ACTIVE
}

void Tab4Handler()
{
  //ADD CODE TO RUN WHILE THIS TAB IS ACTIVE
}

// ------------------------ UI ----------------------------------------

void MainMenu() //Draws the Main Menu with touch tags to select between each tab
{
  //Draws each of the buttons in Grey
  CleO.RectangleColor(GREY);

  CleO.Tag(TAB1);
  CleO.RectangleXY((0.01 * SCREENWIDTH), (0.01 * SCREENHEIGHT), 112, 50);

  CleO.Tag(TAB2);
  CleO.RectangleXY((0.251 * SCREENWIDTH), (0.01 * SCREENHEIGHT), 112, 50);

  CleO.Tag(TAB3);
  CleO.RectangleXY((0.491 * SCREENWIDTH), (0.01 * SCREENHEIGHT), 112, 50);

  CleO.Tag(TAB4);
  CleO.RectangleXY((0.731 * SCREENWIDTH), (0.01 * SCREENHEIGHT), 122, 50);

  //Sets the selected button colour
  if (ShowSettings == false)
  {
    CleO.RectangleColor(LIGHT_BLUE);
  }
  else
  {
    CleO.RectangleColor(INDIAN_RED);
  }

  //Outlines in BLUE the selected mode
  switch (MenuMode)
  {
    case 1:
      CleO.Tag(TAB1);
      CleO.RectangleXY((0.01 * SCREENWIDTH), (0.01 * SCREENHEIGHT), 112, 50);
      break;
    case 2:
      CleO.Tag(TAB2);
      CleO.RectangleXY((0.251 * SCREENWIDTH), (0.01 * SCREENHEIGHT), 112, 50);
      break;
    case 3:
      CleO.Tag(TAB3);
      CleO.RectangleXY((0.491 * SCREENWIDTH), (0.01 * SCREENHEIGHT), 112, 50);
      break;
    case 4:
      CleO.Tag(TAB4);
      CleO.RectangleXY((0.731 * SCREENWIDTH), (0.01 * SCREENHEIGHT), 122, 50);
      break;
  }

  //Outputs the button names with the assigned tags
  CleO.Tag(TAB1);
  CleO.StringExt(FONT_SANS_4, (0.125 * SCREENWIDTH), (0.1 * SCREENHEIGHT), WHITE, MM, 0, 0, "Tab 1"); //Update each of these names so that they correlate to the tabs

  CleO.Tag(TAB2);
  CleO.StringExt(FONT_SANS_4, (0.375 * SCREENWIDTH), (0.1 * SCREENHEIGHT), WHITE, MM, 0, 0, "Tab 2");

  CleO.Tag(TAB3);
  CleO.StringExt(FONT_SANS_4, (0.625 * SCREENWIDTH), (0.1 * SCREENHEIGHT), WHITE, MM, 0, 0, "Tab 3");

  CleO.Tag(TAB4);
  CleO.StringExt(FONT_SANS_4, (0.87 * SCREENWIDTH), (0.1 * SCREENHEIGHT), WHITE, MM, 0, 0, "Tab 4");

  //Draws the settings option for each page - this is whole new system modified by the Menu int

  CleO.Tag(SETTINGS);
  CleO.RectangleXY((0.90 * SCREENWIDTH), (0.18 * SCREENHEIGHT), 40, 40);
  if (ShowSettings == false)
  {
    CleO.StringExt(FONT_SANS_5, (0.945 * SCREENWIDTH), (0.25 * SCREENHEIGHT), WHITE, MM, 0, 0, "*");
  }
  else
  {
    CleO.StringExt(FONT_SANS_5, (0.945 * SCREENWIDTH), (0.245 * SCREENHEIGHT), WHITE, MM, 0, 0, "X");
  }

  CleO.RectangleColor(GREY);
  CleO.Tag(0); //Sets the tag to 0 so now new UI elements are labelled when drawn
}

void Tab1Page()
{
  //ADD YOUR UI CONTENT HERE
  CleO.StringExt(FONT_SANS_4, (0.50 * SCREENWIDTH), (0.70 * SCREENHEIGHT), BLACK, MM, 0, 0, "1 - ADD STUFF");
}

void Tab2Page()
{
  //ADD YOUR UI CONTENT HERE
  CleO.StringExt(FONT_SANS_4, (0.50 * SCREENWIDTH), (0.70 * SCREENHEIGHT), BLACK, MM, 0, 0, "2 - ADD STUFF");
}

void Tab3Page()
{
  //ADD YOUR UI CONTENT HERE
  CleO.StringExt(FONT_SANS_4, (0.50 * SCREENWIDTH), (0.70 * SCREENHEIGHT), BLACK, MM, 0, 0, "3 - ADD STUFF");
  
}

void Tab4Page()
{
  //ADD YOUR UI CONTENT HERE
  CleO.StringExt(FONT_SANS_4, (0.50 * SCREENWIDTH), (0.70 * SCREENHEIGHT), BLACK, MM, 0, 0, "4 - ADD STUFF");
  
}

void Tab1Settings()
{
  CleO.StringExt(FONT_SANS_4, (0.50 * SCREENWIDTH), (0.70 * SCREENHEIGHT), BLACK, MM, 0, 0, "TAB 1 SETTINGS");
}

void Tab2Settings()
{
  CleO.StringExt(FONT_SANS_4, (0.50 * SCREENWIDTH), (0.70 * SCREENHEIGHT), BLACK, MM, 0, 0, "TAB 2 SETTINGS");
}

void Tab3Settings()
{
  CleO.StringExt(FONT_SANS_4, (0.50 * SCREENWIDTH), (0.70 * SCREENHEIGHT), BLACK, MM, 0, 0, "TAB 3 SETTINGS");
}

void Tab4Settings()
{
  CleO.StringExt(FONT_SANS_4, (0.50 * SCREENWIDTH), (0.70 * SCREENHEIGHT), BLACK, MM, 0, 0, "TAB 4 SETTINGS");
}

void DrawSettingsButtons() //Draws increment and decrement buttons for settings menus
{

  CleO.RectangleColor(GREY);

  CleO.Tag(INCREMENTBUTTON);
  CleO.RectangleXY((0.40 * SCREENWIDTH), (0.13 * SCREENHEIGHT), 100, 50);
  CleO.StringExt(FONT_SANS_6, (0.50 * SCREENWIDTH), (0.20 * SCREENHEIGHT), WHITE, MM, 0, 0, "+");

  CleO.Tag(DECREMENTBUTTON);
  CleO.RectangleXY((0.40 * SCREENWIDTH), (0.72 * SCREENHEIGHT), 100, 50);
  CleO.StringExt(FONT_SANS_6, (0.50 * SCREENWIDTH), (0.80 * SCREENHEIGHT), WHITE, MM, 0, 0, "-");

  CleO.Tag(DONEBUTTON);
  CleO.RectangleXY((0.75 * SCREENWIDTH), (0.43 * SCREENHEIGHT), 50, 50);
  CleO.StringExt(FONT_SANS_6, (0.80 * SCREENWIDTH), (0.50 * SCREENHEIGHT), WHITE, MM, 0, 0, "X");

}

//Intro Animation - you can change what it says to whatever you like
void Intro()  //Draws DS Style Intro Animation Isolated from the rest of the program
{
  double MoveDownPer = 0;
  double MoveUpPer = 1;
  int AnimationTime = millis() + 1500;
  int AnimationInc = millis() + 200;

  //Shapes Move Together
  while (millis() < AnimationTime && MoveDownPer < 0.42)
  {
    if (millis() > AnimationInc)
    {
      MoveDownPer = MoveDownPer + 0.05;
      MoveUpPer = MoveUpPer - 0.05;
      AnimationInc = millis() + 30;
    }

    CleO.Start();
    CleO.StringExt(FONT_SANS_4, (0.32 * SCREENWIDTH), (0.46 * SCREENHEIGHT), BLACK, MM, 0, 0, "CLE");
    CleO.StringExt(FONT_SANS_7, (0.62 * SCREENWIDTH), (0.50 * SCREENHEIGHT), BLACK, MM, 0, 0, "Arc");

    CleO.RectangleJustification(MM);
    CleO.RectangleCorner(6);
    CleO.RectangleColor(BLACK);
    CleO.RectangleXY((0.42 * SCREENWIDTH), (MoveDownPer * SCREENHEIGHT), 30, 30);

    CleO.RectangleCorner(5);
    CleO.RectangleColor(WHITE);
    CleO.RectangleXY((0.42 * SCREENWIDTH), (MoveDownPer * SCREENHEIGHT), 20, 20);

    CleO.RectangleCorner(6);
    CleO.RectangleColor(GREY);
    CleO.RectangleXY((0.42 * SCREENWIDTH), (MoveUpPer * SCREENHEIGHT), 30, 30);

    CleO.RectangleCorner(5);
    CleO.RectangleColor(WHITE);
    CleO.RectangleXY((0.42 * SCREENWIDTH), (MoveUpPer * SCREENHEIGHT), 20, 20);
    CleO.Show();
  }

  CleO.Start();

  CleO.StringExt(FONT_SANS_4, (0.32 * SCREENWIDTH), (0.46 * SCREENHEIGHT), BLACK, MM, 0, 0, "CLE");
  CleO.StringExt(FONT_SANS_7, (0.62 * SCREENWIDTH), (0.50 * SCREENHEIGHT), BLACK, MM, 0, 0, "Arc");

  CleO.RectangleJustification(MM);
  CleO.RectangleCorner(6);
  CleO.RectangleColor(BLACK);
  CleO.RectangleXY((0.42 * SCREENWIDTH), (0.46 * SCREENHEIGHT), 30, 30);

  CleO.RectangleColor(GREY);
  CleO.RectangleXY((0.42 * SCREENWIDTH), (0.56 * SCREENHEIGHT), 30, 30);

  CleO.RectangleCorner(5);
  CleO.RectangleColor(WHITE);
  CleO.RectangleXY((0.42 * SCREENWIDTH), (0.56 * SCREENHEIGHT), 20, 20);

  CleO.RectangleColor(WHITE);
  CleO.RectangleXY((0.42 * SCREENWIDTH), (0.46 * SCREENHEIGHT), 20, 20);

  CleO.CircleExt((0.40 * SCREENWIDTH), (0.85 * SCREENHEIGHT), 10, 14, GREY, MM, 0, 0);
  CleO.CircleExt((0.60 * SCREENWIDTH), (0.85 * SCREENHEIGHT), 10, 14, GREY, MM, 0, 0);

  CleO.RectangleCorner(1);
  CleO.RectangleColor(GREY);
  CleO.RectangleXY((0.50 * SCREENWIDTH), (0.85 * SCREENHEIGHT), 100, 28);
  CleO.RectangleColor(WHITE);
  CleO.RectangleXY((0.50 * SCREENWIDTH), (0.85 * SCREENHEIGHT), 100, 23);

  CleO.StringExt(FONT_SANS_3, (0.50 * SCREENWIDTH), (0.85 * SCREENHEIGHT), GREY, MM, 0, 0, "V1.0");

  CleO.Show();

  delay(1500);
}

void AnimationLoop() //Displays the frame refresh rate
{

  CleO.LineColor(GREY);

  double CurrentSecond = ((millis() / 1000U) % 10); //Gets the seconds in millis
  double CurrentMiliSecond = ((millis() / 100U) % 10);

  CleO.Line((0 * SCREENWIDTH), (0.985 * SCREENHEIGHT), (((CurrentSecond / 10) + (CurrentMiliSecond / 100)) * SCREENWIDTH), (0.985 * SCREENHEIGHT));
}

void TouchHandler() //Handles Touch Interactions
{
  int16_t x, y, dur, TouchedTag;
  CleO.TouchCoordinates(x, y, dur, TouchedTag);
  tag = TouchedTag;
  if (tag == 1 || tag == 2 || tag == 3 || tag == 4)
  {
    MenuMode = tag;
  }

  //Debounce Delay prevents fast cycling
  if (tag == SETTINGS && millis() > SettingsDebounceTimer)
  {
    //This toggles the settings function
    if (ShowSettings == false)
    {
      ShowSettings = true;
    }
    else
    {
      ShowSettings = false;
    }
    SettingsDebounceTimer = millis() + 255;
  }
}
