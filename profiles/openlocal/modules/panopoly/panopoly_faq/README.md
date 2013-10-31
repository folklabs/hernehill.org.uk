Panopoly FAQ
====================

Description
---------------------

Panopoly FAQ is a feature for providing a simple question / answer information display via pages and blocks. 

Structurally, Panopoly FAQ creates a FAQ (Frequently Asked Questions) content type which via taxonomy terms creates various "faq groupings" which can be displayed via a default FAQ page and/or displayed in specific blocks. 

It's built for using Drupal's basic structured and modules like Views and Panels. It provides optimal backend storage via Drupal content and taxonomy and flexible usage via Panels, Page Manager and Panelizer. 

Installation
---------------------

1. Download Module from https://github.com/markwk/panopoly_faq using 7.x-2.x branch. 
2. Add and enable various dependencies. 
4. Enable these modules: faq_blocks, faq_expand, faq_widgets, panopoly_faq_page, panopoly_faq_question, panopoly_faq_widgets

Basic Concepts
---------------------

* Once installed, Panopoly FAQ feature provides a default FAQ page at <site-url>/fag
* Individual "FAQ" and "FAQ groupings" can be created and managed at admin/structure/faq
* Additional changes can be managed via the taxonomy page at admin/structure/taxonomy/faq_group

Basic Usage: Adding FAQ Groupings and FAQ questions
---------------------

* After enabling, go to Manage FAQ page at admin/structure/faq
* Use "Add new group" to create different FAQ groupings for your questions/answers
* Once created, use "Add new question" to create various combinations of questions and answers. (NOTE: you can use html or WYSIWYG editors to create dynamic combinations) 
* (SIDENOTE: the administrative title is optional and will not be displayed in FAQ)
* Once a grouping of questions is created, you can use the "Reorder Questions" link to organize the order of questions in a grouping
* After you have created a series of groupings, you can use the "Manage FAQ page ordering" link to change the overall order of the FAQ page 

Advanced Usage: Understanding Structure of FAQ
---------------------

* Panopoly FAQ feature uses taxonomy terms to create "FAQ groupings," so in order to remove the display of a FAQ grouping go to admin/structure/taxonomy/faq_group and click "edit" next to the specific term and "uncheck" the "Show this group on FAQ page"
* Adding FAQ Groupings to various pages and area, Panopoly FAQ uses Panels and Panelizer to do some of its magic. As such, if you are using a Panopoly-powered site, you should be be able to add these blocks to various areas of your site. With Panelizer enabled, lick "Customize this page" and after click FAQ group to add a FAQ grouping to that the particular page. 
* In order to various mixing and matching, you can create a simple page and add different FAQ groupings as needed. 
