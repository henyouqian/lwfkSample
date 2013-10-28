#ifndef __LW_SLIDER_SCENE_H__
#define __LW_SLIDER_SCENE_H__

namespace lw {
    class Sprite;
    class Sound;
}

class SliderScene: public lw::SceneNode
{
public:
    SliderScene();
    ~SliderScene();
    
private:
    virtual void vLoad();
    virtual void vUnload();
    virtual void vEnter();
    
    virtual bool vTouchBegan(const lw::Touch &touch);
    virtual bool vTouchMoved(const lw::Touch &touch);
    virtual bool vTouchEnded(const lw::Touch &touch);
    virtual bool vTouchCanceled(const lw::Touch &touch);
};

extern SliderScene gSliderScene;


#endif //__LW_TITLE_SCENE_H__