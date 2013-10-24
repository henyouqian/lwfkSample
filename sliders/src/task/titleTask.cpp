#include "prefix.h"
#include "titleTask.h"
#include "sliderTask.h"


TitleTask gTitleTask;


TitleTask::TitleTask() {
    lwinfo("TitleTask::TitleTask()");
}


TitleTask::~TitleTask() {
    
}

void TitleTask::vStart() {
    lw::Sprite::addAtlas("icon.atlas");
    _pSprite = lw::Sprite::create("cirrus-64.png", "normal");
    _pSound = lw::Sound::create("button.wav");
    _pSound2 = lw::Sound::create("b.wav");
    
    
    lw::SpriteButtonDef def;
    def.callback = this;
    def.sptNormal = "cirrus-64.png";
    def.sptDown = "delta-64.png";
    def.sptDisable = "jcb-64.png";
    def.x = 100;
    def.y = 100;
    def.overrideW = def.overrideH = 300;
    
    _pBtn = lw::Button::create(def);
    
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
    _pSprite->draw();
    _pBtn->draw();
}

void TitleTask::vTouchBegan(const lw::Touch &touch) {
    //_pSound->play();
//    if (touch.y < 480) {
//        _pSound->play();
//    } else {
//        _pSound2->play();
//    }
    
    _pBtn->touchBegan(touch);
}

void TitleTask::vTouchMoved(const lw::Touch &touch) {
    
}

void TitleTask::vTouchEnded(const lw::Touch &touch)  {
    _pBtn->touchEnded(touch);
}

void TitleTask::vTouchCanceled(const lw::Touch &touch)  {
    _pBtn->touchCanceled(touch);
}

void TitleTask::vDown(lw::Button* pButton) {
    _pSound->play();
}

void TitleTask::vClick(lw::Button* pButton) {
    _pSound2->play();
    this->stop();
    gSliderTask.start();
}






