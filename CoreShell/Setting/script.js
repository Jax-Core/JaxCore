var currentPage = 'info';
var currentModule = 'YourFlyouts';

const pageIconReference = {
general: 'settings',
appearance: 'format_paint',
animation: 'animation',
render: 'token',
position: 'dashboard',
media: 'music_note',
layout: 'view_array',
modules: 'extension',
shop: 'add_shopping_cart'
}

function capitalizeFirstLetter(string) {
  return string.charAt(0).toUpperCase() + string.slice(1);
}

function changeToPage(page) {
  /* ------------------------------- Transition ------------------------------- */
  const transition_el = document.querySelector('.transition');
  transition_el.classList.add('is-active');
  setTimeout(() => {
    transition_el.classList.remove('is-active');
    /* --------------------------------- Switch --------------------------------- */
    if (currentPage != page) {
      document.getElementById('pageListItemIcon-'+currentPage).classList.remove("pageSelector-icon--selected");
      document.getElementById('pageListItemName-'+currentPage).classList.remove("pageSelector-name--selected");
      document.getElementById('page-'+currentPage).style.display = "none";
      currentPage = page;
    }
    document.getElementById('pageListItemIcon-'+page).classList.add("pageSelector-icon--selected");
    document.getElementById('pageListItemName-'+page).classList.add("pageSelector-name--selected");
    document.getElementById('page-'+page).style.display = "flex";
  }, 600);
}

/* -------------------------------------------------------------------------- */
/*                                    Load                                    */
/* -------------------------------------------------------------------------- */
window.onload = function() {

  /* ------------------------------- Header icon ------------------------------ */
  document.querySelector('.pageList-headerImage').setAttribute('src', 'https://raw.githubusercontent.com/Jax-Core/JaxCore/main/%40Resources/Icons/LibraryIcons/'+currentModule+'.png')
  changeToPage(currentPage);

  console.debug(data);
    for (let i = 0; i < data.pageArray.length; i++) {
      var name = data.pageArray[i];
      /* --------------------------- Generate page list --------------------------- */
      if (name != 'div') {
        document.querySelector('.pageList').insertAdjacentHTML('beforeend', `
        <a class="pageList-item" onclick="changeToPage('`+name+`')">
        <span class="pageSelector-icon material-symbols-outlined" id="pageListItemIcon-`+name+`">`+pageIconReference[name]+`</span>
        <span class="pageSelector-name" id="pageListItemName-`+name+`">`+capitalizeFirstLetter(name)+`</span>
        </a>
        `);
      } else {
        document.querySelector('.pageList').insertAdjacentHTML('beforeend', `
        <div class="pageList-div"></div>
        `);
      }
      /* ------------------------ Generate page containers ------------------------ */
      document.querySelector('body').insertAdjacentHTML('beforeend', `
      <div class="set-container" id="page-`+name+`">
      <h1 class="set-pageName">`+capitalizeFirstLetter(name)+`</h1>
      </div>
      `);
      /* -------------------------- Import page contents -------------------------- */
      var pageContents = data[name];
      console.debug(pageContents);
      for (const key in pageContents) {
        console.log('Block type: '+key.slice('0', '-2'))
        switch (key.slice('0', '-2')) {
          case 'category':
            document.getElementById('page-'+name).insertAdjacentHTML('beforeend', `
            <h2 class="set-categoryName">`+pageContents[key]+`</h2>
            `);
            break;
          case 'option':
            var optionProperties = pageContents[key];
            switch (optionProperties['type']) {
              case 'text':
                document.getElementById('page-'+name).insertAdjacentHTML('beforeend', `
                <div class="set-item">
                  <label class="set-itemName">
                    <span>`+optionProperties['title']+`</span>
                    <span>`+optionProperties['description']+`</span>
                  </label>
                  <input type="text"></input>
                </div>
                `);
                break;
              case 'bool':
                document.getElementById('page-'+name).insertAdjacentHTML('beforeend', `
                <div class="set-item">
                <label class="set-itemName">
                <span>`+optionProperties['title']+`</span>
                <span>`+optionProperties['description']+`</span>
                </label>
                <label class="slider-container">
                <span class="slider-label" data-on="On" data-off="Off"></span>
                <input type="checkbox">
                <span class="slider"></span>
                </label>
                </div>
                `);
                break;
              }
            break;
              
        }
      }
    }

    /* ------------------------------- Transition ------------------------------- */
  
    const transition_el = document.querySelector('.transition');
    setTimeout(() => {
      transition_el.classList.remove('is-active');

    }, 500);
    // });
}
