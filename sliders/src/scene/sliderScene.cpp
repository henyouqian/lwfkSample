#include "prefix.h"
#include "sliderScene.h"
#include "titleScene.h"


SliderScene gSliderScene;


SliderScene::SliderScene() {
    lwinfo("SliderScene::SliderScene()");
}

SliderScene::~SliderScene() {
    
}

void SliderScene::vLoad() {
    
}

void SliderScene::vUnload() {
    
}

void SliderScene::vEnter() {
    glClearColor(1.f, 0.69f, 0.61f, 1.0f);
}

bool SliderScene::vTouchBegan(const lw::Touch &touch) {
    lw::SceneNode::switchTo(&gTitleScene, true);
    return false;
}

bool SliderScene::vTouchMoved(const lw::Touch &touch) {
    return false;
}

bool SliderScene::vTouchEnded(const lw::Touch &touch)  {
    return false;
}

bool SliderScene::vTouchCanceled(const lw::Touch &touch)  {
    return false;
}





