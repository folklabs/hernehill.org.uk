; $Id: debut_forum.make.inc,v 1.1 2011/02/23 23:31:10 nedjo Exp $

; Drupal version
core = 7.x
api = 2

; Contrib modules
projects[advanced_forum][subdir] = contrib
projects[advanced_forum][version] = 2.0

projects[apps_compatible][subdir] = contrib
projects[apps_compatible][version] = 1.0-alpha3

projects[captcha][subdir] = contrib
projects[captcha][version] = 1.0-beta2

projects[ctools][subdir] = contrib
projects[ctools][version] = 1.2

;projects[debut_comment][version] = 2.x-dev
projects[debut_comment][subdir] = debut
projects[debut_comment][download][type] = git
projects[debut_comment][download][url] = http://git.drupal.org/project/debut_comment.git
projects[debut_comment][download][branch] = 7.x-2.x

projects[features][subdir] = contrib
projects[features][version] = 1.0

projects[pathauto][subdir] = contrib
projects[pathauto][version] = 1.2

projects[strongarm][subdir] = contrib
projects[strongarm][version] = 2.0
