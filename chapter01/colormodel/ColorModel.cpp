#include "ColorModel.hpp"

ColorModel::ColorModel(){

}

static inline void register_this() {
    qmlRegisterType<ColorModel>(
        "sstd.color.model",
        1, 0,
        "ColorModel");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)






