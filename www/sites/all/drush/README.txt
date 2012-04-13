Bluespark Labs git repositories ignore sites/all/drush/drushrc.php with the
intention that you symlink this file to the specific drushrc.php file provided
inside the multi-site environment folder corresponding to the current server
environment.

These are example commands that you might execute on the command line from the
drupal root folder to link the drushrc.php file to a specific environment. 

Production server example:
ln -s ../../example.com/drushrc.php sites/all/drush/drushrc.php

Development server example:
ln -s ../../example.gobsp.com/drushrc.php sites/all/drush/drushrc.php

Localhost developer example.
ln -s ../../example.local/drushrc.php sites/all/drush/drushrc.php
