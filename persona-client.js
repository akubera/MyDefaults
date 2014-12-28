
$(_persona_init);

var g_current_user = null;

function _persona_init()
{
  var user_did_login = false;
  
  var login_action_url = '/login',
     logout_action_url = '/logout';
  
  navigator.id.watch({
    loggedInUser: g_current_user,
    onlogin: function(assertion) {
      if (!user_did_login) return;
      $.ajax({
        type: 'POST',
        url: login_action_url,
        data: {assertion: assertion},
        success: function(res, status, xhr) { window.location.reload(); },
        error: function(xhr, status, err) {
          navigator.id.logout();
          alert("Login failure: " + err);
        }
      });
    },
    onlogout: function() {
      $.ajax({
        type: 'POST',
        url: logout_action_url,
        success: function(res, status, xhr) { window.location.reload(); },
        error: function(xhr, status, err) { alert("Logout failure: " + err); }
      });
    }
  });

  $("#persona-login").click(_login_click);

  function _login_click(ev)
  {
    user_did_login = true;
    navigator.id.request();
  }


}
