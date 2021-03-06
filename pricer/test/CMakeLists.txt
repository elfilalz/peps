############### Pricer Tests ###############

include_directories(${CMAKE_SOURCE_DIR}/src/pricer)
include_directories(${CMAKE_SOURCE_DIR}/src/quote)

file(GLOB TEST_SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" *.cpp)
foreach(testsourcefile ${TEST_SOURCES})
    string(REPLACE ".cpp" "" testname ${testsourcefile})
    add_executable(${testname} ${testsourcefile})
    target_link_libraries(${testname} peps curl ${LIBS})
endforeach(testsourcefile ${TEST_SOURCES})

############### Pricer Tests ###############

include_directories(${CMAKE_SOURCE_DIR}/src/quote)

add_executable(quoteTests
    quote/TestAllQuote.cpp
    quote/TimeUtilsTest.cpp
    quote/QuoteTest.cpp
    quote/DataBaseManagerTest.cpp
    )

add_executable(pricerTests
    pricer/TestAllPricer.cpp
    pricer/test_calibration.cpp
    pricer/test_pricer_actigo.cpp
    )

target_link_libraries(quoteTests peps gtest gtest_main curl ${LIBS})
add_custom_target(runQuoteTests quoteTests)

target_link_libraries(pricerTests peps gtest gtest_main curl ${LIBS})
add_custom_target(runPricerTests pricerTests)
