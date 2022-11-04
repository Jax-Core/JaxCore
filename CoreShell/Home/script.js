// const _resourceDir = RainmeterAPI.GetVariable('@')
var currentPage = 'discover';

function GoToCorePage (pageName) {
    // RainmeterAPI.Bang('[!WriteKeyvalue Variables Skin.Name '+pageName+' "'+_resourceDir+'CacheVars\\Configurator.inc"][!WriteKeyvalue Variables Skin.Set_Page Info "'+_resourceDir+'CacheVars\\Configurator.inc"][!ActivateConfig "#JaxCore\\Main" "Settings.ini"]')
}

function OpenCoreCtx() {
    // RainmeterAPI.Bang('[!UpdateMeasureGroup CurPos.XY][!CommandMeasure Ctx.Gen:M "StartCtx()"]')
}

function changeToPage(page) {
  console.log(page);
  /* ------------------------------- Transition ------------------------------- */
  // const transition_el = document.querySelector('.transition');
  // transition_el.classList.add('is-active');
  setTimeout(() => {
    // transition_el.classList.remove('is-active');
    /* --------------------------------- Switch --------------------------------- */
    if (currentPage != page) {
      document.getElementById('pageSelectorItem-'+currentPage).classList.remove("pageSelector--selected");
      document.getElementById('page-'+currentPage).style.display = "none";
      currentPage = page;
    }
    document.getElementById('pageSelectorItem-'+page).classList.add("pageSelector--selected");
    document.getElementById('page-'+page).style.display = "flex";
  }, 0);
}

window.onload = function() {
  changeToPage('discover');

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
}