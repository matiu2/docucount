Quick and Easy Accounting 
=========================

Concept:
--------

 1. Import transactions from bank website
 2. Create a regex to match transactions
 3. Apply tags to all transactions that fit that regex
 4. Once all transactions are tagged, craete reports for certain tags

For example:
~~~~~~~~~~~~

 1. Any transaction with the name "Dick Smith" is tagged 'elerctronic equipment'
 2. In your expernse report you say 'electronic equipment'


Data Object Types
-----------------

 * Account
   * name
   * number
   * start date
   * start balance
 * Transaction
   * id
   * account
   * description
   * date
   * amount
   * Tags -<
 * Tag
   * name
   * Transactions -<
 * Regex
   * name
   * regex
 * Report
   * name
   * Tags to include -<
 * Import - Records as import (so you can undo an import later)
   * name
   * date
   * regex value -- Applied to the CSV
   * Transactions -<
   * original csv data

Gui Pages
---------

 * Import transactions
 * List Transactions
 * Create Regex
 * List Regexs
 * Create Tags
 * List Tags
