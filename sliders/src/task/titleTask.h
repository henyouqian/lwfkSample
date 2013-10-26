#ifndef __LW_TITLE_TASK_H__
#define __LW_TITLE_TASK_H__

#include "lwfk/lwTask.h"
#include "lwfk/UI/lwButton.h"

namespace lw {
    class Sprite;
    class Sound;
}

class TitleTask: public lw::Task, lw::ButtonCallback
{
public:
    TitleTask();
    ~TitleTask();
    
private:
    virtual void vStart();
    virtual void vStop();
    virtual void vUpdate();
    virtual void vDraw();
    
    virtual void vTouchBegan(const lw::Touch &touch);
    virtual void vTouchMoved(const lw::Touch &touch);
    virtual void vTouchEnded(const lw::Touch &touch);
    virtual void vTouchCanceled(const lw::Touch &touch);
    
    virtual void vDown(lw::Button* pButton);
    virtual void vClick(lw::Button* pButton);
    
    lw::Sprite *_pSprite;
    lw::Sound *_pSound;
    lw::Sound *_pSound2;
    lw::Button *_pBtn;
    lw::SpriteNode *_pSptNode;
    lw::SpriteNode *_pSptNode2;
};

extern TitleTask gTitleTask;


#endif //__LW_TITLE_TASK_H__