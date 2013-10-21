#ifndef __LW_TITLE_TASK_H__
#define __LW_TITLE_TASK_H__

#include "lwfk/lwTask.h"

namespace lw {
    class Sprite;
}

class TitleTask: public lw::Task
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
    
    lw::Sprite *_pSprite;
};

extern TitleTask gTitleTask;


#endif //__LW_TITLE_TASK_H__