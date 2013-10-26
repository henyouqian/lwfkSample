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
    
    lw::SpriteNode::addAtlas("icon.atlas");
    _pSptNode = lw::SpriteNode::create("cirrus-64.png", "normal", NULL);
    _pSptNode->setPivot(32, 32);
    _pSptNode->setPos(100, 100);
    
    _pSptNode2 = lw::SpriteNode::create("paypal-64.png", "normal", _pSptNode);
    _pSptNode2->setPivot(0, 32);
    _pSptNode2->setPos(64, 32);
    
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
    delete _pSptNode;
    delete _pSound;
    delete _pSound2;
    delete _pBtn;
}


void TitleTask::vUpdate() {
    _pBtn->update();
    
    static float rot = 0.f;
    rot += 0.04f;
    _pSptNode->setRotateZ(rot);
    
    _pSptNode2->setRotateZ(rot*.5f);
    _pSptNode2->setScale(1, sinf(rot*3));
    
    _pSptNode->update();
}


void TitleTask::vDraw() {
    //_pSprite->draw();
    _pSptNode->draw();
    //_pBtn->draw();
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






