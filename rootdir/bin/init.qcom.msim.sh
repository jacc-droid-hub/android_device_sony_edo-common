#!/vendor/bin/sh

model=`grep -am1 '[Mm][Oo][Dd][Ee][Ll]:' /dev/block/by-name/LTALabel | sed -e 's/^.*[Mm][Oo][Dd][Ee][Ll]:[ ]*\([A-Za-z0-9-]*\).*$/\1/'` 2> /dev/null

case "$model" in
    "XQ-AT42" | "XQ-AT52" | "XQ-AT72" | "XQ-AS42" | "XQ-AS52" | "XQ-AS62" | "XQ-AS72" )
        setprop vendor.radio.hardware.sku ds;;
    * )
        setprop vendor.radio.hardware.sku ss;;
esac

if [ "$model" == "" ]; then
    setprop vendor.radio.ltalabel.model "JP"
else
    setprop vendor.radio.ltalabel.model "$model"
fi
