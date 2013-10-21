#include "prefix.h"
#include "titleTask.h"
#include "lwfk/lwlog.h"
#include "lwfk/lwTexture.h"
#include "lwfk/lwSprite.h"
#include "lwfk/lwRenderState.h"
#include "lwfk/lwSound.h"
#include "lwfk/lwText.h"
#include "lwfk/lwApp.h"

#include <math.h>


TitleTask gTitleTask;


TitleTask::TitleTask() {
    lwinfo("TitleTask::TitleTask()");
}


TitleTask::~TitleTask() {
    
}

void TitleTask::vStart() {
    glClearColor(0.31f, 0.69f, 0.61f, 1.0f);
    _pSprite = lw::Sprite::createFromFile("title.png", "normal");
}

void TitleTask::vStop() {
    delete _pSprite;
}


void TitleTask::vUpdate() {
    
}


void TitleTask::vDraw() {
    _pSprite->draw();
}

void TitleTask::vTouchBegan(const lw::Touch &touch) {
    lwinfo("vTouchBegan");
}

void TitleTask::vTouchMoved(const lw::Touch &touch) {
    lwinfo("vTouchMoved");
}

void TitleTask::vTouchEnded(const lw::Touch &touch)  {
    lwinfo("vTouchEnded");
}

void TitleTask::vTouchCanceled(const lw::Touch &touch)  {
   lwinfo("vTouchCanceled");
}







