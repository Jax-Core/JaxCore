const _resourceDir = RainmeterAPI.GetVariable('@')

function GoToCorePage (pageName) {
    RainmeterAPI.Bang('[!WriteKeyvalue Variables Skin.Name '+pageName+' "'+_resourceDir+'SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page Info "'+_resourceDir+'SecVar.inc"][!ActivateConfig "#JaxCore\\Main" "Settings.ini"]')
}

function OpenCoreCtx() {
    RainmeterAPI.Bang('[!UpdateMeasureGroup CurPos.XY][!CommandMeasure Ctx.Gen:M "StartCtx()"]')
}

if (document.addEventListener) {
  document.addEventListener('contextmenu', function(e) {
    OpenCoreCtx()
    e.preventDefault();
}, false);
} else {
    document.attachEvent('oncontextmenu', function() {
    OpenCoreCtx()
    window.event.returnValue = false;
  });
}