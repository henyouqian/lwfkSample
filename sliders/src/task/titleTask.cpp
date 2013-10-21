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
    lw::Sprite::addAtlas("icon.atlas");
    _pSprite = lw::Sprite::createFromAtlas("cirrus-64.png", "normal");
    _pSound = lw::Sound::create("button.wav");
    _pSound2 = lw::Sound::create("b.wav");
    
    
    lw::ButtonDefAtlas def;
    def.callback = this;
    def.atlasNormal = "cirrus-64.png";
    def.atlasDown = "delta-64.png";
    def.atlasDisable = "jcb-64.png";
    def.x = 100;
    def.y = 100;
    def.overrideW = def.overrideH = 300;
    
    _pBtn = new lw::Button(def);
    
    glClearColor(0.31f, 0.69f, 0.61f, 1.0f);
}

void TitleTask::vStop() {
    delete _pSprite;
    delete _pSound;
    delete _pSound2;
    delete _pBtn;
}


void TitleTask::vUpdate() {
    _pBtn->update();
}


void TitleTask::vDraw() {
    //_pSprite->draw();
    _pBtn->draw();
}

void TitleTask::vTouchBegan(const lw::Touch &touch) {
    lwinfo("vTouchBegan");
//    if (touch.y < 480) {
//        _pSound->play();
//    } else {
//        _pSound2->play();
//    }
    
    _pBtn->touchBegan(touch);
}

void TitleTask::vTouchMoved(const lw::Touch &touch) {
    lwinfo("vTouchMoved");
}

void TitleTask::vTouchEnded(const lw::Touch &touch)  {
    lwinfo("vTouchEnded");
    _pBtn->touchEnded(touch);
}

void TitleTask::vTouchCanceled(const lw::Touch &touch)  {
   lwinfo("vTouchCanceled");
    _pBtn->touchCanceled(touch);
}

void TitleTask::vDown(lw::Button* pButton) {
    _pSound->play();
}

void TitleTask::vClick(lw::Button* pButton) {
    _pSound2->play();
}






