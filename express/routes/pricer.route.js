const express = require('express');
const router = express.Router();

const PricerController = require('../controllers/pricer.controller');
const UserController = require('../controllers/user.controller');

router.post('/', UserController.userOnly, PricerController.actigoDelta);
router.post('/hedging', UserController.userOnly, PricerController.hedging);

// Export the Router
module.exports = router;