import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { NgbModule } from '@ng-bootstrap/ng-bootstrap';
import { HttpClientModule } from '@angular/common/http';
import { FormsModule } from '@angular/forms';
import { ChartsModule } from 'ng2-charts/ng2-charts';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HomeComponent } from './home/home.component';
import { FinancialDataComponent } from './financial-data/financial-data.component';
import { StockComponent } from './stock/stock.component';
import { PricingComponent } from './pricing/pricing.component';
import { ContactComponent } from './contact/contact.component';

import { StockService } from './services/stock.service';
import { SpotService } from './services/spot.service';
import { YahooFinanceService } from './services/yahoo-finance.service';

@NgModule({
  declarations: [
    AppComponent,
    HomeComponent,
    FinancialDataComponent,
    StockComponent,
    PricingComponent,
    ContactComponent
  ],
  imports: [
    NgbModule.forRoot(),
    BrowserModule,
    HttpClientModule,
    FormsModule,
    ChartsModule,
    AppRoutingModule
  ],
  providers: [
    StockService,
    SpotService,
    YahooFinanceService
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }