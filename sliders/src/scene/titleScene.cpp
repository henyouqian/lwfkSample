#include "prefix.h"
#include "titleScene.h"
#include "sliderScene.h"


TitleScene gTitleScene;


TitleScene::TitleScene() {
    lwinfo("TitleScene::TitleScene()");
}


TitleScene::~TitleScene() {
    
}

void TitleScene::vLoad() {
    lw::Sprite::addAtlas("icon.atlas");
    _pSprite = lw::Sprite::create("cirrus-64.png", "normal");
    
    lw::SpriteNode::addAtlas("icon.atlas");
    _pSptNode = lw::SpriteNode::create(this, "cirrus-64.png", "normal");
    _pSptNode->setPivot(32, 32);
    _pSptNode->setPos(100, 100);
    
    _pSptNode2 = lw::SpriteNode::create(_pSptNode, "paypal-64.png", "normal");
    _pSptNode2->setPivot(0, 32);
    _pSptNode2->setPos(64, 32);
    
    _pSound = lw::Sound::create("button.wav");
    _pSound2 = lw::Sound::create("b.wav");
    
    
    lw::SpriteButtonDef def;
    def.parent = this;
    def.callback = this;
    def.sptNormal = "cirrus-64.png";
    def.sptDown = "delta-64.png";
    def.sptDisable = "jcb-64.png";
    def.x = 100;
    def.y = 100;
    def.overrideW = def.overrideH = 300;
    
    _pBtn = lw::Button::create(def);
}

void TitleScene::vUnload() {
    delete _pSprite;
    delete _pSptNode;
    delete _pSound;
    delete _pSound2;
    delete _pBtn;
}

void TitleScene::vEnter() {
    glClearColor(0.31f, 0.69f, 0.61f, 1.0f);
}

void TitleScene::vUpdate() {
    _pBtn->update();
    
    static float rot = 0.f;
    rot += 0.04f;
    _pSptNode->setRotateZ(rot);
    
    _pSptNode2->setRotateZ(rot*.5f);
    _pSptNode2->setScale(1, sinf(rot*3));
    
    _pSptNode->update();
}

bool TitleScene::vTouchBegan(const lw::Touch &touch) {
    lw::SceneNode::switchTo(&gSliderScene, false);
    return false;
}

void TitleScene::vDown(lw::Button* pButton) {
    _pSound->play();
}

void TitleScene::vClick(lw::Button* pButton) {
    _pSound2->play();
}






