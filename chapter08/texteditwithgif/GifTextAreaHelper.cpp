#include "GifTextAreaHelper.hpp"
#include "PlaceHolderImageProvider.hpp"

GifTextAreaHelper::GifTextAreaHelper(){

}

void GifTextAreaHelper::classBegin(){
    Super::classBegin();
    auto varEngine = qmlEngine(this);
    assert(varEngine);
    if(!varEngine->imageProvider( PlaceHolderImageProvider::providerName() )){
        varEngine->addImageProvider(PlaceHolderImageProvider::providerName(),
                                    new PlaceHolderImageProvider);
    }
}

static inline void register_this() {
    qmlRegisterType<GifTextAreaHelper>(
        "sstd.giftextarea.help",
        1, 0,
        "GifTextAreaHelper");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
















