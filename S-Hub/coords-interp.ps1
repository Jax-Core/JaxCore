# $w0 = 960
# $h0 = 540
# $w = 3840
# $h = 1080
# $m = 200

# $x0 = 470
# $y0 = 500
function coords-interp {
    if (($w/1920) -lt ($h/1080)) { $scale = $w / 1920 } else { $scale = $h / 1080 }
    $margin = $m * $scale

    if (($w/$w0) -lt ($h/$h0)) {
        $sf = $w/$w0
    } else {
        $sf = $h/$h0
    }

    $margin0 = $margin / $sf
    $r0 = [math]::Round($w0 / $h0,3)
    $r = [math]::Round($w / $h,3)

    "sf = $sf, scale = $scale, margin = $margin, margin0 = $margin0, r0 = $r0, r = $r"


    if ($r0 -eq $r) {
        $x = $x0 * $sf
        $y = $y0 * $sf
    } else {
        $cw = $w / 2
        $ch = $h / 2
        $cw0 = $w0 / 2
        $ch0 = $h0 / 2

        if ($x0 -le $margin0) {
            "x is left"
            $x = $x0 * $sf
        } elseif ($x0 -gt $margin0 -and $x0 -lt $($w0 - $margin0)) {
            "x is center"
            $x = $cw - ($cw0 - $x0) * $sf
        } else {
            "x is right"
            $x = $w - ($w0 - $x0) * $sf
        }
        if ($y0 -le $margin0) {
            "y is top"
            $y = $y0 * $sf
        } elseif ($y0 -gt $margin0 -and $y0 -lt $($h0 - $margin0)) {
            "y is center"
            $y = $ch - ($ch0 - $y0) * $sf
        } else {
            "y is bottom"
            $y = $h - ($h0 - $y0) * $sf
        }
    }
    return $x, $y
}