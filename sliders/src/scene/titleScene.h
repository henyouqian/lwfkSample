#ifndef __LW_TITLE_SCENE_H__
#define __LW_TITLE_SCENE_H__

namespace lw {
    class Sprite;
    class Sound;
}

class TitleScene: public lw::SceneNode, lw::ButtonCallback
{
public:
    TitleScene();
    ~TitleScene();
    
private:
    virtual void vLoad();
    virtual void vUnload();
    virtual void vEnter();
    virtual void vUpdate();
    
    virtual bool vTouchBegan(const lw::Touch &touch);
    
    virtual void vDown(lw::Button* pButton);
    virtual void vClick(lw::Button* pButton);
    
    lw::Sprite *_pSprite;
    lw::Sound *_pSound;
    lw::Sound *_pSound2;
    lw::Button *_pBtn;
    lw::SpriteNode *_pSptNode;
    lw::SpriteNode *_pSptNode2;
};

extern TitleScene gTitleScene;


#endif //__LW_TITLE_SCENE_H__