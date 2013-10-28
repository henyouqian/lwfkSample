#include "prefix.h"
#include "task/titleTask.h"
#include "scene/titleScene.h"
#include "lwfk/lwLog.h"

void lwapp_init()
{
    //gTitleTask.start();
    lw::SceneNode::switchTo(&gTitleScene, false);
}

void lwapp_quit()
{
    
}




