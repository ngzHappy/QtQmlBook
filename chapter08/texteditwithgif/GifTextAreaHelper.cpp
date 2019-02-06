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
















