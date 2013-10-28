//
// Prefix header for all source files of the 'dev' target in the 'dev' project
//

#ifdef __IPHONE_5_0
    #import <Availability.h>
    #import <TargetConditionals.h>
#endif

#ifdef __OBJC__
    #import <UIKit/UIKit.h>
    #import <Foundation/Foundation.h>
#endif

#ifdef __cplusplus
    #include "lwfk/lwPrefix.h"
    #include <unistd.h>

    #include "lwfk/lwlog.h"
    #include "lwfk/lwTexture.h"
    #include "lwfk/lwSprite.h"
    #include "lwfk/lwRenderState.h"
    #include "lwfk/lwSound.h"
    #include "lwfk/lwText.h"
    #include "lwfk/lwApp.h"
    #include "lwfk/node/lwSceneNode.h"
    #include "lwfk/node/lwSpriteNode.h"
    #include "lwfk/UI/lwButton.h"
#endif

